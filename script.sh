for i in 1 2 3 4
do
    ./myht < teste/teste${i}.in
    cat teste/teste${i}.out
    echo
    echo
done
