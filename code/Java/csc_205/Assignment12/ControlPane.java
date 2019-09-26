// Assignment #: Arizona State University CSE205 #12
//         Name: Luke Schulz
//    StudentID: 1211984746
//      Lecture: M-W 6 PM
//  Description: The ControlPane is a subclass of BorderPane. It contains 6 buttons
//  including two start buttons, two stop buttons, and two reverse buttons. It also
//  contains two labels and two Slider objects. It also contains two sub Panes -- two
//  objects of BicyclePane class, one for the red bicycle and one for the blue bicycle.
//  ---- is where you need to add your own code.

import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.TilePane;

import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;

import javafx.scene.paint.Color;
import javafx.geometry.Orientation;
import javafx.geometry.Insets;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;

public class ControlPane extends BorderPane
{
  //1 for the red bicycle control, 2 for the blue bicycle control
   private BicyclePane bicycle1, bicycle2;

  //leftPane contains two groups of buttons and slides;
  //rightPane contains the BicyclePane
   private GridPane leftPane, rightPane;
   private TilePane sub1, sub2; // changes sub to LowerCase for consistency
   private BorderPane sub3, sub4,leftup,leftdown; // changes subs to LC

   private Button start1, start2, stop1, stop2, reverse1, reverse2;
   private Label label1, label2;
   private Slider slider1, slider2;
   private int width, height;

  //The constructor creates 6 buttons, 2 sliders, and 2 bicycle panels
  //and organize them using layouts.
   public ControlPane(int width, int height)
   {
      this.setPrefSize(width, height);

      //create 2 bicycle panes and arrange them using GridLayout
      bicycle1 = new BicyclePane(Color.RED, Color.YELLOW , 600);

      //bicycle2 is BLUE color with BEIGE background color
      bicycle2 = new BicyclePane( Color.BLUE , Color.BEIGE , 600 );

   	  //Step #1: set up the layout
   	  //rightPane is a GridPane, contains above two bicycle panes
      rightPane = new GridPane();
      rightPane.setHgap(10);
      rightPane.setVgap(20);
      //---- // attach bicycle1
      rightPane.add(bicycle1, 0, 0); // first col, 1st row
      //---- .// attach bicycle 2
      rightPane.add(bicycle2, 0 , 1); // first col, 2nd row.

      //instantiate each components

      //**RED/TOP BUTTONS / LABEL ** //
      start1 = new Button("Start Red");
      stop1 = new Button("Stop Red");
      reverse1 = new Button("Reverse Red");
      label1 = new Label("Red Speed");

      //instantiate slider1 and set its properties
      //** RED / TOP SLIDER ** //
      slider1 = new Slider(0,50,20);
      slider1.setMajorTickUnit(10);
      slider1.setMinorTickCount(1);
      slider1.setShowTickLabels(true);
      slider1.setShowTickMarks(true);
      slider1.setOrientation(Orientation.VERTICAL);

      //** BLUE / BOTTOM BUTTONS / LABEL ** //
      start2 = new Button("Start Blue");
      stop2 = new Button("Stop Blue");
      reverse2 = new Button("Reverse Blue");
      label2 = new Label("Blue Speed");

      //instantiate slider2 and set its properties
      //** BLUE / BOTTOM SLIDER ** //
      slider2 = new Slider(0,50,20);
      slider2.setMajorTickUnit(10);
      slider2.setMinorTickCount(1);
      slider2.setShowTickLabels(true);
      slider2.setShowTickMarks(true);
      slider2.setOrientation(Orientation.VERTICAL);


      //Sub1 contains the 3 buttons for the red bicycle
      // IS TILEPANE

      sub1 = new TilePane(Orientation.VERTICAL); // NEED SIZE ???
      sub1.setPrefColumns(1);
      sub1.setVgap(10);
      sub1.setHgap(10);
      sub1.getChildren().add(start1);
      sub1.getChildren().add(stop1); 
      sub1.getChildren().add(reverse1);

      //Sub2 contains the 3 buttons for the blue bicycle
      //IS TILEPANE

      sub2 = new TilePane(Orientation.VERTICAL); // NEED SIZE?
      sub2.setPrefColumns(1);
      sub2.setVgap(10);
      sub2.setHgap(10);
      sub2.getChildren().add(start2);
      sub2.getChildren().add(stop2);
      sub2.getChildren().add(reverse2);

      //Sub3 contains one label and one slider for the red bicycle
      // IS BORDERPANE


      sub3 = new BorderPane(); // NEED SIZE?
      sub3.setTop(label1);
      sub3.setLeft(slider1);

      //Sub4 contains one label and one slider for the blue bicycle
      //IS BORDERPANE

      sub4 = new BorderPane();
      sub4.setTop(label2);
      sub4.setLeft(slider2);

      //leftup contains sub1 & sub3 for the red bicycle
      // IS BORDERPANE
      leftup = new BorderPane();
      leftup.setLeft(sub1);
      leftup.setCenter(sub3);
  	  

       //leftdown contains sub2 & sub4 for the blue bicycle
       //IS BORDERPANE
      leftdown = new BorderPane();
      leftdown.setLeft(sub2);
      leftdown.setCenter(sub4);

       //leftPane contains leftup & leftdown
      //IS GRIDPANE
      leftPane = new GridPane();

      leftPane.setHgap(10);
      leftPane.add(leftup, 0, 0);
      leftPane.add(leftdown, 0, 1);

      //Remember ControlPane is a BorderPane
      this.setLeft(leftPane);
      this.setCenter(rightPane);
      //this.setTop(new TextField("Top")); 
      //this.setBottom(new TextField("Bottom")); 
      //this.setLeft(new TextField("Left")); 
      //this.setRight(new TextField("Right")); 
      //this.setCenter(new TextField("Center")); 

      //Step #3: 1) add ButtonHandler to each of the buttons
      //----

      //Step #3: 2)add SliderHandler to the two sliders
	  //----
   }

   //Step #2:(A)ButtonHandler class
   private class ButtonHandler implements EventHandler<ActionEvent>
   {
      public void handle(ActionEvent event)
      {
         Object action = event.getSource();

        //----
        //----
      }
   } //end of ButtonHandler

   //Step #2:(B)SliderHandler class
   private class SliderHandler implements ChangeListener<Number>
   {
      public void changed(ObservableValue<? extends Number> observable,
                           Number oldValue, Number newValue)
      {
         //----
      }
   }


} //end of ControlPane