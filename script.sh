for i in 1 2 3 4
do
    ./myht < teste/teste${i}.in > teste/teste${i}.out
    diff teste/teste${i}.out teste/teste${i}.sol
done
