obj(balloon).
obj(clothesline).
obj(frisbee).
obj(waterTower).

person(mr_barrada).
person(ms_gort).
person(mr_klatu).
person(mr_nikto).

day(tuesday).
day(wednesday).
day(thursday).
day(friday).

day_before(tuesday,wednesday).
day_before(wednesday,thursday).
day_before(thursday,friday).

earlier(X,Y) :- day_before(X,Y).
    
earlier(X, Y) :- day_before(Z, Y), earlier(X, Z).

solve :-
    obj(B_O),obj(G_O),obj(K_O),obj(N_O),
    all_different([B_O, G_O, K_O, N_O]),

    day(B_D),day(G_D),day(K_D),day(N_D),
    all_different([B_D,G_D,K_D,N_D]),

    Triples = [ [mr_barrada, B_O, B_D],
  			      [ms_gort, G_O, G_D],
			        [mr_klatu, K_O, K_D],
  		        [mr_nikto, N_O, N_D] ],


    % 1 Mr. Klaatu made his sighting at some point earlier in the week than the one who saw the balloon, but at some point later in the week than the one who spotted the Frisbee (who isn't Ms. Gort).

	\+ (member([ms_gort, frisbee, _], Triples)),

    
    earlier(X,Y),
    earlier(Y,Z),
    
    (member([_,frisbee, X],Triples)),
    (member([mr_klatu,_, Y],Triples)),
    (member([_,balloon, Z],Triples)),
    

    % 2 Friday'a sighting was made by either Ms. Barada or the one who saw a clothesline (or both).

    (member([mr_barrada, _, friday], Triples);

	member([_, clothesline, friday], Triples)),

    % 3 Mr. Nikto did not make his sighting on Tuesday.

    \+ (member([mr_nikto, _, tuesday], Triples)),

    % 4 Mr. Klaatu isn't the one whose object turned out to be a water tower.

    \+ (member([mr_klatu, waterTower, _], Triples)),

    
    
    tell(mr_barrada, B_O, B_D),
    
    tell(ms_gort, G_O, G_D),
    
    tell(mr_klatu, K_O, K_D),

    tell(mr_nikto, N_O, N_D).

all_different([H | T]) :- member(H, T), !, fail.        % (1)
all_different([_ | T]) :- all_different(T).             % (2)
all_different([_]).                                     % (3)

tell(X, Y, Z) :-
    
	write(X), write(' saw the '), write(Y), write(' on '), write(Z),write('.'), nl.