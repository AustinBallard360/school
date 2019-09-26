/* Luke Schulz, HW 14 ! */



/* BEGIN RULES */
foo(ANSWER , X , Y):-
	X =< 0 , ANSWER is Y , !.
foo(ANSWER , X , Y):-
	Y=< 0 , ANSWER is X , !.
foo(ANSWER , X , Y):- 
	X >= Y ,
	X2 is X - 1 ,
	Y2 is Y - 2 ,
	foo(A2 , X2, Y2), /*this will set A2 */
	ANSWER is X + A2, !.
foo(ANSWER , X , Y):-
	X < Y ,
	X2 is X - 2 ,
	Y2 is Y - 3 ,
	foo(A2 , X2, Y2) ,
	ANSWER is Y + A2 , !.



q1 :- foo(A , 5 , 6) ,
	write('The Answer of foo(A , 5 , 6) is ') ,
	write(A) .

