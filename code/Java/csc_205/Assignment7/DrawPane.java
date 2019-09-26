// Assignment #: Arizona State University CSE205 #7
//         Name: Luke Schulz
//    StudentID: 1211984746
//      Lecture: M-W 6:00 PM
//  Description: The DrawPane class creates a canvas where we can use
//               mouse key to draw either a Rectangle or a Circle with different
//               colors. We can also use the the two buttons to erase the last
//				 drawn shape or clear them all.
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.RadioButton; // Bulk copy from Assignment suggestions
import javafx.scene.control.ToggleGroup;
import javafx.scene.layout.TilePane;
import javafx.scene.layout.VBox;
import javafx.scene.layout.HBox;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import java.lang.Math; 

//Pre-included on assignment download
import javafx.scene.layout.Pane;
import javafx.scene.layout.BorderPane;
import javafx.scene.shape.Shape;
import javafx.scene.shape.Rectangle;
import javafx.scene.shape.Circle;
import javafx.scene.paint.Color;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.geometry.Orientation;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.input.MouseEvent;

import java.util.ArrayList;
import java.util.List;

public class DrawPane extends BorderPane
{
   private Button undoBtn, eraseBtn;
   private ComboBox<String> colorCombo;
   private RadioButton rbRect, rbCircle;
   private ArrayList<Shape> shapeList;
   private ObservableList<Shape> shapeObsList;
   private Pane canvas;
   //declare any other necessary instance variables here
   private String colors;
   private VBox leftVBox;
   private HBox bottomHBox;
   private ToggleGroup group;
   private String whatColor = "BLACK";
   private Color c = Color.BLACK;
   //vars for mouse location for shape
   private Double x1,y1,x2,y2; // vars for mouse click co-ordinates
   private int shapeIndex = 0; // index counter our canvas node
   private int shapeIsRect = 1; // default to rectangle

   //Constructor
   public DrawPane()
   {
      //Step #1: initialize each instance variable and set up layout
      undoBtn = new Button("Undo");
         undoBtn.setMinWidth(80.0);
         undoBtn.setOnAction(new ButtonHandler()); //  trigger Button handler on click.

      eraseBtn = new Button("Erase");
         eraseBtn.setMinWidth(80.0);
         eraseBtn.setOnAction(new ButtonHandler()); //  trigger Button handler on click.

      //Create the color comboBox and intial its default color
      // define array of color names
      String colors[] = { 
         "Black", "Blue", "Green", "Red", "Yellow", "Orange", "Pink"
      };
      colorCombo = new ComboBox<String>(FXCollections.observableArrayList(colors)); // fill combo box with array of colors
         colorCombo.setOnAction(new ColorHandler()); // register event handler
         colorCombo.getSelectionModel().selectFirst(); // default to the first option of comboBox ("Black")

      //Create the two radio buttons and also a ToggleGroup
      //so that the two radio buttons can be selected
      //mutually exclusively. Otherwise they are indepedant of each other
      group = new ToggleGroup(); // group for putting the radio buttons as a pair

         rbRect = new RadioButton("Rectangle");//radio button 1 (Rectangle)
            rbRect.setToggleGroup(group); // add radio button to group
            rbRect.setSelected(true); // default this button to selected state.
             rbRect.setOnAction(new ShapeHandler()); // register event handling

         rbCircle = new RadioButton("Circle"); // Radio Button 2 (Circle)
            rbCircle.setToggleGroup(group); // add radio button to group.
            rbCircle.setOnAction(new ShapeHandler()); // register event handling
            
      //initialize shapeList, it is a data structure we used
      shapeList = new ArrayList<Shape>();
         shapeObsList = FXCollections.observableList(shapeList); // observable list for ShapeList

      //canvas is a Pane where we will draw rectagles and circles on it
      canvas = new Pane();// The pane is called canvas, but is not a Canvas class object.
         canvas.setStyle("-fx-background-color: beige;"); // set background color beige
            try{ // basic Exception handling which i ended up not using.
         }catch(Exception ex){
            System.out.println("exception bro");
         }

      //initialize the remaining instance variables and set up
      //the layout
      leftVBox = new VBox(25);  
         leftVBox.getChildren().addAll(colorCombo,rbRect,rbCircle);
            leftVBox.setSpacing(40); // for display, keeps some space vertically between nodes
            leftVBox.setPadding(new Insets(10, 10, 10, 10)); // padding between nodes
            leftVBox.setMinSize(100,100); // mimin 

      bottomHBox = new HBox(10);
         bottomHBox.getChildren().addAll(undoBtn,eraseBtn);
            bottomHBox.setAlignment(Pos.CENTER);
            bottomHBox.setSpacing(10); // for display, keeps some space vertically between nodes
            bottomHBox.setPadding(new Insets(10, 10, 10, 10)); // padding between nodes
            bottomHBox.setMinSize(500,50); // mimin 

      this.setLeft(leftVBox); // apply the VBOX to the left of parent item (BorderPane)
      this.setBottom(bottomHBox); // add HBox to the bottom of parent BorderPane
      this.setCenter(canvas); // add the canvas to center of parent BorderPane
      //----

      //Step #3: Register the source nodes with its handler objects
      //canvas.addEventHandler(MouseEvent.MOUSE_DRAGGED, new MouseHandler()); ** THIS is for the drag event, which i have not written yet
      canvas.addEventHandler(MouseEvent.MOUSE_PRESSED, new MouseHandler());
      canvas.addEventHandler(MouseEvent.MOUSE_RELEASED, new MouseHandler());
     


    }

   //Step #2(A) - MouseHandler
   private class MouseHandler implements EventHandler<MouseEvent>
   {
      public void handle(MouseEvent event)
      {
		 //handle MouseEvent here
         if(event.getEventType()==MouseEvent.MOUSE_PRESSED){ // when mouse is clicked DOWN
            x1=event.getX(); // get initial mouse position X value
            y1=event.getY(); // get initial mouse pos Y val
         } // end mouse click down
         //if(event.getEventType()==MouseEvent.MOUSE_DRAGGED){} // case for when mouse is dragged, unused as of now
         if(event.getEventType()==MouseEvent.MOUSE_RELEASED){ // when mouse click is released
            x2=event.getX(); // get final mouse pos X val
            y2=event.getY();// get final mouse pos Y val
            Double height = Math.abs(y1-y2); // calculate height as absolute value of difference between two Y values
            Double width = Math.abs(x2-x1); // calc width as Absolute value of difference between two x vals
            Double radius =Math.sqrt(height*height + width*width)/2; // this is a calculation for the radius. A^2 + B^2 = C^2 ( then cut in half cause it felt better)

            if(shapeIsRect==1){ // create the shapes by cases, checks for flag set by ShapeHandler. idk if this is ideal.
               Rectangle rec1 = new Rectangle(x1,y1,width,height); // create rectangle
                  rec1.setFill(c); // set the rectangles color as defined by the ColorHandler
                  rec1.setStroke(Color.BLACK); // set shape outline as Black
                  shapeObsList.addAll(rec1); // add to our observable list.
                  canvas.getChildren().add(shapeObsList.get(shapeIndex)); // Add to canvase node from object list.
                  shapeIndex++; // incriment index for keeping track of objects in list / node
            } // end if rectangle
            if(shapeIsRect==0){ // Creates circle by cases, checks against flag set by ShapeHandler.
               Circle circ1 = new Circle(x1,y1,radius,c); // create circle object
                  circ1.setStroke(Color.BLACK); // set outline = black
                  shapeObsList.addAll(circ1); // add to observableList
                  canvas.getChildren().add(shapeObsList.get(shapeIndex)); // add to pane node
                  shapeIndex++; // incriment index for keeping track of objects.
            } // end if circle
      } // end mouse click released.
   }//end handle()
}//end MouseHandler

   //Step #2(B)- A handler class used to handle events from Undo & Erase buttons
   private class ButtonHandler implements EventHandler<ActionEvent>
   {
      public void handle(ActionEvent event)
      { 
         if(event.getSource()==eraseBtn){ // if erase button is pressed
            canvas.getChildren().clear(); // clear all nodes from canvas pane
            shapeObsList.clear(); // clear the obs array also 
            shapeIndex = 0; // Also reset the index so your counting adds up if you choose to add more shapes.
            //int shapeArrSize= shapeObsList.size(); 
         }

         if(event.getSource()==undoBtn){ // if undo button is pressed
            canvas.getChildren().remove(shapeObsList.get(shapeIndex-1)); // remove the previous shape node.
            shapeObsList.remove(shapeIndex-1); // remove the shape object also from the observable array
            shapeIndex--; // de-incriment the index counter so it matches
        }//end if undo
		 
      }// end handle()
   }//end ButtonHandler

   //Step #2(C)- A handler class used to handle events from the two radio buttons
   private class ShapeHandler implements EventHandler<ActionEvent>
   {
      public void handle(ActionEvent event)
      {
         if(rbRect.isSelected()==true){ // IF Rectangle radio button is selected
            shapeIsRect=1; // set the flag to 1
         }
         if(rbCircle.isSelected()==true){ // if circle RB is selected
            shapeIsRect=0; // turn flag off
         }
		 
      }
   }//end ShapeHandler

   //Step #2(D)- A handler class used to handle colors from the combo box
   private class ColorHandler implements EventHandler<ActionEvent>
   {
      public void handle(ActionEvent event)
      {
          whatColor = colorCombo.getValue(); // bunch of conditions for handling each color combobox selection.
          // i wanted to uppercase the string whatColor and pass it as a variable, but i ran into trouble with Color.whatColor not working no matter what
         if(whatColor.equals("Black")){
          c = Color.BLACK;
         }
         if(whatColor.equals("Blue")){
            c = Color.BLUE;
         }
         if(whatColor.equals("Green")){
            c = Color.GREEN;
         }
         if(whatColor.equals("Red")){
            c = Color.RED;
         }
         if(whatColor.equals("Yellow")){
            c = Color.YELLOW;
         }
         if(whatColor.equals("Orange")){
            c = Color.ORANGE;
         }
         if(whatColor.equals("Pink")){
            c = Color.PINK;
         }
		  //write your own codes here
      }
   }//end ColorHandler

}//end class DrawPane