/*LUKE SCHULZ */
/*CSC 240 4/13/19 */
/* Database for family tree. It consists of facts and rules. */
/* A portion of the family tree has been implemented for you */
/* Facts */
male(kam).
male(rob).
female(ana).
female(syd).
father_of(kam, rob). /* kam is the father of rob */
father_of(kam, syd). /* kam is the father of syd */
mother_of(ana, rob). /* ana is the mother of rob */
mother_of(ana, syd). /* ana is the mother of syd */
mother_of(gma , ana).
/* Rules */
/*Question 1 */
is_male(X) :-
male(X);
father_of(X, _).
/*Question 2 */
is_female(X) :-
female(X);
mother_of(X, _).

/*Question #3 */
parent_of(X,Y) :-
father_of(X,Y);
mother_of(X,Y).

/*Question #4 */
sibling_of(X,Y) :-
mother_of(Z , X) , /*must have same mother, any mother will do*/
mother_of(Z, Y);
father_of(Q , X) , /*OR, must have same father, any father will do*/
father_of(Q , Y).

/*Question #5*/
grandmother_of(X,Y) :-
mother_of(X , Z) , /* must be the mother of the mother of Y */
mother_of(Z , Y).

/*Question #6, recursion*/
descendent_of(X,Y) :-
parent_of(X,Y).
descendent_of(X,Y) :-
parent_of(X,Z),
descendent_of(Z,Y).





