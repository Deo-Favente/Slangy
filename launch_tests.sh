make 
echo "TESTS CORRECTS"
echo "-----------------------------------"
for file in Tests/Corrects/*.sl
do
    if [ -f "$file" ] 
        then
            echo "Running calculette on $file (should pass)"
            ./main $file
            echo "-----------------------------------"
        fi
done
echo "TESTS INCORRECTS"
echo "-----------------------------------"
for file in Tests/Incorrects/*.sl
do
    if [ -f "$file" ] 
        then
            echo "Running calculette on $file (should not pass)"
            ./main $file
            echo "-----------------------------------"
        fi
done
make clean