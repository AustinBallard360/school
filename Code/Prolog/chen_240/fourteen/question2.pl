/* Luke Schulz, HW 14 ! */

get_last([X] , X) . % Stop case when List is same as tail %%% STOPPING CONDITION
get_last([_|T] , X):- %take a list, ignore the head, pop the tail %%% N SIZE PROBLEM
	get_last(T, X) . % pass tail as list, recurse %%% M SIZE SOLUTION

remove_last([_] , []). % Stop if you got a empty solution / new tail %%% STOPPING CONDITION
remove_last([Head|Tail] , [Head|NewTail]):- %% pass the head with mystery tail
	remove_last(Tail , NewTail). %% M size solution, recurse, pass 2nd param list as mystery tail only 
	


qsort([],[]) :- !. % copied from the slides a lot here %% STOPPING CONDITION
qsort(L, Sorted):- %% N SIZE PROBLEM
	get_last(L , Pivot) , % Take list and get the last element for use as pivot.
	remove_last(L , ListNoPivot) , %Get the remainder of list without our pivot (this works how tail works in the slides example from chen)
	split(Pivot , ListNoPivot , L1, L2 ), %% Do the split into groups
	qsort(L1 , Sorted1), %Recurse on the splitted lists %% M SIZE SOLUTION
	qsort(L2, Sorted2), % recurse on split lists %% M SIZE SOLUTION
	append(Sorted1, [Pivot|Sorted2] , Sorted). %% put all your split lists back together %% N SIZE SOLUTION
	

split(_,[],[],[]).		% stopping condition %% Basically coppied from slides
split(Pivot,[X|T],[X|Le],Gt):-		% take first from Tail
	X=<Pivot, split(Pivot,T,Le,Gt).	% and put it into Le
split(Pivot,[X|T],Le,[X|Gt]):-		% take first from Tail
	X > Pivot, split(Pivot,T,Le,Gt).	% and put it into Gt


%% TEST CASES %%%%%%%%%%%%
 q1 :- get_last([a, b, c, x, y], E) ,
 	write('E = ') , write(E) .

 q2 :-  remove_last([a, b, c, x, y], Ls) ,
 	write('Ls = ') ,  write(Ls).

 q3 :-  qsort([8, 3, 4, 12, 25, 4, 6, 1, 9, 22, 6], Sorted),
 	write('Sorted = ') , write(Sorted).

