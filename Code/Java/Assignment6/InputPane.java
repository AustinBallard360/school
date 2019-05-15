// Assignment #: Arizona State University CSE205 #6
//         Name: Luke Schulz
//    StudentID: 1211984746
//      Lecture: M-W 6:00 pm
//  Description: InputPane generates a pane where a user can enter
//  a laptop information and create a list of available laptops.
//import all other necessary javafx classes here
import javafx.scene.layout.*;
import javafx.geometry.*;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import java.io.*;
import java.util.*;
import javafx.event.*;
import java.util.ArrayList;
import javafx.scene.layout.HBox;
import javafx.scene.layout.GridPane;
import javafx.scene.control.TextField;
import javafx.scene.control.Button;
import javafx.scene.control.MenuButton;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.collections.ObservableList;
import javafx.scene.layout.HBox;



public class InputPane extends HBox
{
	//GUI components
	private GridPane gp; // main component, holds the labels and fields and button in the left half of tab hbox

	private TextArea rightArea; // this is the right half of HBox, displays laptops which have been input

	private Label dTextLab; // this is for displaying output to user "laptop added" OR "Wrond Data type"
	private Label brandLab; // these are the labels for the form columns/Text Fields for user input of laptops
	private Label modelLab; 
	private Label cpuLab;
	private Label ramLab;
	private Label priceLab;

	private TextField brandField; // this is the text fields on the left which user inputs laptop infos
	private TextField modelField;
	private TextField cpuField;
	private TextField ramField;
	private TextField priceField;

	private PurchasePane pPane; // this is the PurchasePane class instance for updating laptopList

	private Button enterBut; // button for entering a laptop

   private ArrayList<Laptop> laptopList;

   //The relationship between InputPane and PurchasePane is Aggregation
   //private PurchasePane purchasePane;
   //----

	//constructor
	public InputPane(ArrayList<Laptop> list, PurchasePane pPane)
	{
		this.pPane = pPane;
		this.laptopList = list;
		this.setSpacing(10);
   		this.setPadding(new Insets(10, 10, 10, 10));
		//this.purchasePane = pPane;

		//Step #1: initialize each instance variable and set up the layout
		//----
		rightArea = new TextArea();
			rightArea.setText("");

		brandLab = new Label("Brand");
		modelLab = new Label("Model");
		cpuLab = new Label("CPU(GHz)"); // all the labels for text fields
		ramLab = new Label("RAM(GB)");
		priceLab = new Label("Price($)");
		dTextLab = new Label("");

		brandField = new TextField("");
		modelField = new TextField(""); // all the text fields for user input
		cpuField = new TextField("0");
		ramField = new TextField("0");
		priceField = new TextField("0");

		brandLab.setLabelFor(brandField);
		modelLab.setLabelFor(modelField); // attach the labels. im not even 100% sure what this does
		cpuLab.setLabelFor(cpuField);
		ramLab.setLabelFor(ramField);
		priceLab.setLabelFor(priceField);


		enterBut = new Button("Enter a Laptop Info."); // NEEDS EVENT HANDLING
		//enterBut.setMinSize(200,20);
			enterBut.setOnAction(new ButtonHandler());

		//create a GridPane hold those labels & text fields
		gp = new GridPane();
			gp.setMinSize(300,400);
			gp.setHgap(10); //horizontal gap in pixels => that's what you are asking for
			gp.setVgap(10); //vertical gap in pixels
   			gp.setPadding(new Insets(10, 10, 10, 10));

   		gp.add(dTextLab,0,0,2,1); // this is display of error/confirmation text, spans 2 columns
   		gp.addRow(1,brandLab,brandField);
   		gp.addRow(2,modelLab,modelField); // add labels => textfields for each
   		gp.addRow(3,cpuLab,cpuField);
   		gp.addRow(4,ramLab,ramField);
   		gp.addRow(5,priceLab,priceField);
   		gp.add(enterBut,0,6,2,1 ); // enter laptop button, spans two columns for full text display.
   
   		//builds the HBox for class, gripane on the left, text area on the right.
   		this.getChildren().addAll(gp,rightArea);

	} //end of constructor

  //Step #2: Create a ButtonHandler class
  //ButtonHandler listens to see if the buttont "Enter a Laptop Info." is pushed or not,
  //When the event occurs, it get a laptop's brand, model, CPU, RAM and price
  //information from the relevant text fields, then create a new Laptop object and add it inside
  //the laptopList. Meanwhile it will display the laptop's information inside the text area.
  //It also does error checking in case any of the textfields are empty or wrong data was entered.
    private class ButtonHandler implements EventHandler<ActionEvent>
   	 {
   	    //Override the abstact method handle()
   	    @Override
   	    public void handle(ActionEvent e)
        {
        	try{ // attempts to set variables based on user input, looks for exceptions
				//declare any necessary local variables here
				//---
				String lstring,oldstring,addedStrings; // take all user input as strings
				String brandS = brandField.getText();
				String modelS = modelField.getText();
				String cpuS = cpuField.getText(); double cpuD = Double.parseDouble(cpuS); // convert strings to doubles
				String ramS = ramField.getText(); double ramD = Double.parseDouble(ramS); // convert strings to doubles
				String priceS = priceField.getText(); double priceD = Double.parseDouble(priceS); // convert strings to doubles
			//when a text field is empty and the button is pushed
			if (brandS.trim().isEmpty() == true || modelS.trim().isEmpty() == true|| cpuS.trim().isEmpty() == true ||
			 ramS.trim().isEmpty()==true ||priceS.trim().isEmpty()==true || brandS==null) // this gets over-ruled by the try/catch unless you have zero for the Doubles.
			{
				dTextLab.setText("Please fill all fields"); // output to user
				dTextLab.setTextFill(Color.web("#ff0000")); // text color red to indicate problem
			}
			else	//for all other cases
         	{
				dTextLab.setText("Laptop added"); // output to user.
				dTextLab.setTextFill(Color.web("#000000")); // set color back to black in case it was changed by previous exceptions
				//at the end, don't forget to update the new arrayList
				Laptop l1 = new Laptop(brandS, modelS, cpuD, ramD, priceD); // create new Laptop Object
					laptopList.add(l1); // add to the ArrayList
					int flag=0; // This is a warning flag, for checking for duplicate laptop items
					int lapArrSize=laptopList.size();
					for(int i=0;i<(lapArrSize-1);i++){ // THIS CHECKS IF TWO OBJECTS ARE EQUAL, TO PREVENT DUPLICATES
						if(laptopList.get(i).toString().equals(l1.toString())){ // use the toString() to compare the string outputs of two objects, this is super hacky but works fine.
							 flag=1; // if you find a duplicate, set flag to 1
						}
					}
					if(flag!=1){ // if no flag, update everything and add the laptop to listview
					pPane.updateLaptopList(l1); // update the ObservableList on PurchasePane class.
						oldstring = rightArea.getText(); // keep log of current laptops on the right text area
						addedStrings=oldstring+l1.toString(); // new text area will have old laptops PLUS new laptop entry
						rightArea.setText(addedStrings); // set text of right text area with old + new laptop entries
					}
					if(flag==1){ // if we have warning flag, display error to user and dont display laptop
						dTextLab.setText("Laptop not added - duplicate"); // output to user
						dTextLab.setTextFill(Color.web("#ff0000")); // text color red to indicate problem
					}
				// After successfully adding a laptop ( or not ), Set fields blank again.
				modelField.setText("");
				brandField.setText("");
				cpuField.setText("");
				ramField.setText("");
				priceField.setText("");
				
            }			}
			catch(Exception ex){ // very broad exception catcher
				dTextLab.setText("Incorrect data format"); // output message to user
				dTextLab.setTextFill(Color.web("#ff0000")); // in red text
			}
      } //end of handle() method
   } //end of ButtonHandler class

}