// Assignment #: Arizona State University CSE205 #6
//         Name: Luke Schulz
//    StudentID: 1211984746
//      Lecture: M-W 6:00 pm
//  Description: PurchasePane displays a list of available laptops
//  from which a user can select to buy. It also shows how many
//  laptops are selected and what is the total amount.
// Import all necessary JavaFX classes
import javafx.geometry.*;
import javafx.scene.paint.Color;
import javafx.scene.control.ListView;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.layout.VBox;
import javafx.scene.layout.HBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.event.ActionEvent;	
import javafx.event.EventHandler;	
import javafx.scene.layout.HBox; 
import javafx.scene.control.Button; 
import javafx.scene.control.Label;
import java.util.ArrayList;
import java.text.DecimalFormat;

public class PurchasePane extends VBox
{
   //GUI components
   private ArrayList<Laptop> laptopList, selectedList;

   //laptopLV for top ListView; selectedLV for bottom ListView
   private ListView<Laptop> laptopLV, selectedLV;
   private ObservableList<Laptop> laptopz;
   private ObservableList<Laptop> selectedz;

   //declare all other necessary GUI variables here
   private Label availableLab,selectedLab,qtyLab,totalLab;
   private HBox hb1, hb2; // 1 is for buttons, 2 is for qty/total amount text
   private Button pickBut, removeBut; // buttons
   private double totalPrice = 0.0; // total price for calculating selected laptops total price

 //constructor
   public PurchasePane(ArrayList<Laptop> list)
   {
   	  //initialize instance variables
    // remembers, the class is a VBox
   	this.setSpacing(10); // for display, keeps some space vertically between nodes
   	this.setPadding(new Insets(10, 10, 10, 10)); // padding between nodes
   	this.setMinSize(400,300); // miminum size for VBox
      this.laptopList = list; // initialize our ArrayList whichw as passed as Param.
      	laptopLV = new ListView<Laptop>(); //node object for displaying laptops
  	  		laptopz = FXCollections.observableArrayList(this.laptopList); // make observable, can update laptop display dynamically.

      selectedList = new ArrayList<Laptop>(); // repeat process for bottom ListView / Selected Laptop array
      	selectedLV = new ListView<Laptop>(); // node for bottom display
      		selectedz = FXCollections.observableArrayList(this.selectedList); // make display updateable 

      //set up the layout
      availableLab = new Label("Available Laptops"); // Display text label above first Listview
        availableLab.setTextFill(Color.web("#341eb2")); // set text to blue
        availableLab.setFont(Font.font("Arial",20)); // make large font

      selectedLab = new Label("Selected Laptops"); // display text label above 2nd list view
        selectedLab.setTextFill(Color.web("#341eb2")); // set text to blue
        selectedLab.setFont(Font.font("Arial",20)); // set large font

      hb2 = new HBox(10); // initialize box for Qty and total Amount labels
      	 hb2.setSpacing(10); // design stuff for hb1
   		   hb2.setPadding(new Insets(10, 10, 10, 10));
   		   hb2.setAlignment(Pos.CENTER);

      qtyLab = new Label("Qty Selected: "); // label for display of quantity text
      	qtyLab.setTextFill(Color.web("#341eb2")); // set color blue
      	qtyLab.setFont(Font.font("Arial",20)); // set font large

      totalLab = new Label("Total Amt: "); // label for display of Total Amount text
      	totalLab.setTextFill(Color.web("#341eb2")); // set text blue
      	totalLab.setFont(Font.font("Arial",20)); // set font large

      hb2.getChildren().addAll(qtyLab,totalLab); // add qty and total amt text to hbox for side by side display

      hb1 = new HBox(10); // hbox for display of middle buttons
      	hb1.setAlignment(Pos.CENTER); // design layout settings
      	hb1.setSpacing(10);
   		hb1.setPadding(new Insets(10, 10, 10, 10));

      pickBut = new Button("Pick a Laptop"); // create buttons
      	pickBut.setOnAction(new ButtonHandler2()); // set handling

      removeBut = new Button("Remove a Laptop"); // create buttons
      	removeBut.setOnAction(new ButtonHandler2()); // set handling

      hb1.getChildren().addAll(pickBut,removeBut); // add buttons to hbox for side by side layout
   	 this.getChildren().addAll(availableLab,laptopLV,hb1,selectedLab,selectedLV,hb2); // add everything to this class object ( VBox )

   } //end of constructor

 //This method refresh the ListView whenever there's new laptop added in InputPane
 //you will need to update the underline ObservableList object in order for ListView
 //object to show the updated laptop list
 public void updateLaptopList(Laptop newLoptop)
 {
     laptopz.addAll(newLoptop); // update the observable list
      laptopLV.setItems(laptopz); // set display to match updated list
 }

 private class ButtonHandler2 implements EventHandler<ActionEvent>
 {
  	//Override the abstact method handle()
  	@Override
    public void handle(ActionEvent e)
    {
		//When "Pick a Laptop" button is pressed and a laptop is selected from
		//the top list
        if (e.getSource()== pickBut) // if button "pick a laptop"
        {
			//System.out.print("you picked a laptop \n");
			Laptop lapNew =laptopLV.getSelectionModel().getSelectedItem();
			  selectedz.addAll(lapNew ); // update observable list
				selectedLV.setItems(selectedz); // set to display updated list

        }
        //when "Remove a Laptop" button is pushed and a laptop is selected from
        //the bottom list
        else if (e.getSource() == removeBut)
         {
         	Laptop lapRemove = selectedLV.getSelectionModel().getSelectedItem();
         		 selectedz.remove(lapRemove); // update observable list
         		 selectedLV.setItems(selectedz); // display updated list

         }
         else //for all other cases
		 {
		 	 System.out.print("NO GO ");//prints to console. not ideal, just some feedback in case of unexpected outcome.
	     }
      	 //update the QtySelect and AmtSelect labels
        int selectedArrayLength = selectedz.size(); // get quantity as size of array
        totalPrice=0; // initialize the totaprice each time you run the event handler
        for(int i=0;i<selectedArrayLength;i++){ // Loop to add up the price of all laptops in the array
          double laptopPrice = selectedz.get(i).getPrice(); // get price of each laptop object
          totalPrice = (totalPrice+laptopPrice); // calculate total
        } // end for loop

        qtyLab.setText("Qty Selected: "+selectedArrayLength); // update text qty display
        totalLab.setText("Total Amt: $"+totalPrice); // update Total Amt txt display
       }
   } //end of ButtonHandler class
} //end of PurchasePane class

