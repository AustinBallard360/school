 javac Assignment8.java;
 javac CategAndNameComparator.java;
 javac IdComparator.java;
 javac Sorts.java;
 java Assignment8 <input1.txt> myout1.txt;
 java Assignment8 <input2.txt> myout2.txt;
 java Assignment8 <input3.txt> myout3.txt;
 java Assignment8 <input4.txt> myout4.txt;

    vimdiff myout1.txt output1.txt;
    vimdiff myout2.txt output2.txt;
    vimdiff myout3.txt output3.txt;
    vimdiff myout4.txt output4.txt;