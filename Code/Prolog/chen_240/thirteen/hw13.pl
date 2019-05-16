/* Luke Schulz, HW 13 ! */

/* Begin Facts! */

/*STATES*/
state(wa).
state(or).
state(ca).
state(az).
state(nm).
state(nv).
state(ut).
state(id).
state(ma).
state(wy).
state(co).
state(nd).
state(sd).
state(ne).
state(ks).

/*Edges! */
edge(wa,or).
edge(wa,id).
edge(or,id).
edge(or,nv).
edge(or,ca).
edge(ca,nv).
edge(ca,az).
edge(az,nv).
edge(az,ut).
edge(az,nm).
/*edge(az,co). FOUR CORNERS DILEMA */
edge(nv,ut).
edge(nv,id).
edge(id,mt).
edge(id,wy).
edge(id,ut).
edge(ut,co).
edge(ut,wy).
/*edge(ut,nm). FOUR CORNERS DILEMA*/
edge(mt,nd).
edge(mt,sd).
edge(mt,wy).
edge(wy,sd).
edge(wy,ne).
edge(wy,co).
edge(co,ne).
edge(co,ks).
edge(co,nm).
edge(nd,sd).
edge(ne,sd).
edge(ne,ks).

/*COLORS bl= blue r=red g=green w=white */
color(wa,bl).
color(or,r).
color(cal,g).
color(az,r).
color(nm,bl).
/*color(nv,g). MISMATCH NV/UT both green */
color(nv,bl).
/*color(id,w). NOT GOOD, MATCHES WYOMING (tried W , BL , G R*/
color(id,g). /*Now it matches utah, i tried all colors or idaho and none work, gonna change utah now*/
color(ut,w). /* tried G BL R W , clashes with utah now */
color(mt,r).
color(wy,bl). /*W ,R  BL(best) G */
color(co,r).
color(nm,bl).
color(sd,g).
color(ne,w). /*was bl*/
color(ks,w). /*was BL WORKS!*/

/* POPULATION FACTS */
population(wa,8).
population(or,4).
population(cal,40).
population(az,7).
population(nm,2).
population(nv,3).
population(id,2). 
population(ut,3). 
population(mt,1).
population(wy,1). 
population(co,6).
population(sd,1).
population(nd,1).
population(ne,2). 
population(ks,3).

topping(p , 5).
topping(m , 10).
topping(b , 7).
topping(o , 3).
topping(c , 8).

/*RULES*/

/*MisColor*/
edges(S1,S2):-
	edge(S1,S2);
	edge(S2,S1).

miscolor(S1,S2,C):-
	edges(S1,S2) ,
	color(S1,C),
	color(S2,C).


totalpopulation([],0) :- !. /*Dont think i need CUT! ??? */
totalpopulation(Lst,Total):-
	car(Pair , Lst ) , /*Get the first pair of list*/
	cdr(PopOfPair , Pair) , /* get the population (Tail of pair).*/
	cdr(RemainingLst , Lst), /*Get Lst - Pair we used */
	totalpopulation(RemainingLst , Total2) , /*Recurse on rest of list*/
	Total is PopOfPair + Total2. /* Total is population of first pair + solution of M size problem*/

car( X ,[X|_]) . /*get first value from pair / list */
cdr(X ,[_|X]) . /*get tail of list */
	
doList([],0). /* I Was having trouble with the population function so I wrote some things to help understand lists */
doList([Head | Tail] , Total):- /*Sum Every Member of list function */
	doList(Tail , T2),
	Total is Head + T2 .


pizza(P, M, B, O, C) :-
/* SET MEMBERSHIP CAP @ 45/Weight for each */
	member(P,[0,1,2,3,4,5,6,7,8,9]), 
	member(M,[0,1,2,3,4]), 
	member(B,[0,1,2,3,4,5,6]), 
	member(O,[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]), 
	member(C,[0,1,2,3,4,5]), 
	TotalWeight is 5*P + 10*M + 7*B + 3*O + 8*C ,
	TotalWeight = 45.



doL :- /* JUST LEARNING */
/*doList([ 1 , 2 , 3 , 4 , 5 ] , T).*/
doList([1,2,3,4] , Total) ,
write(' Total is -> ') , write(Total).




q1 :- miscolor(S1, S2, Color1),
write(S1), write(' and '), write(S2),
write(' have conflict color: '), write(Color1), nl,
totalpopulation([[az, 7], [ca, 40], [ne, 3], [ut, 3], [or, 4],
[id, 2], [wy, 1]], Total),
write('Total = '),
write(Total), nl.

q2 :- pizza(2, 1, 2, 1, 1),
	 pizza(1, M2, 1, O2, C2),
	 pizza(P3, M3, 1, O3, 1) ,
	 write('M2 = ') , write(M2), 
	 write(' O2 = ') , write(O2) , 
	 write(' C2 = ') , write(C2) , nl ,
	 write('P3 = ') , write(P3), 
	 write(' M3 = ') , write(M3) , 
	 write(' O3 = ') , write(O3) , nl .
	






