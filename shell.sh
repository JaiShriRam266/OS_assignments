fileName="My Database"
opt=1
while [ "$opt" -lt 6 ]
do
echo  "Choose one of the Following:"
echo  "1. Create database"
echo  "2. View Records"
echo  "3. Insert new Record"
echo  "4. Delete a Record"
echo  "5. Modify a Record"
echo  "6. Exit"
read opt
case $opt in
1)
if [ -e $fileName ] ; then 
rm $fileName
fi
cont=1
echo  "NAME\t\tNUMBER\t\tADDRESS\n" | cat >> $fileName
while [ "$cont" -gt 0 ]
do
echo  "\nEnter Name"
read name
echo "Enter Phone Number of $name"
read number
echo "Enter Address of $name"
read address
echo "$name\t\t$number\t\t$address\n" | cat >> $fileName
echo "Enter 0 to Stop, 1 to Enter next"
read cont
done
;;
2)
cat $fileName
;;
3)
echo "\nEnter Name"
read name
echo "Enter Phone Number of $name"
read number
echo "Enter Address of $name"
read address
echo  "$name\t\t$number\t\t$address" | cat >> $fileName
;;
4)
echo "Delete record\nEnter Name/Phone Number"
read pattern
temp="temp"
grep  $pattern $fileName | cat >> $temp 
rm $fileName
cat $temp | cat >> $fileName
rm $temp
;;
5)
echo "Modify record\nEnter Name/Phone Number"
read pattern
temp="temp"
grep $pattern $fileName | cat >> $temp
rm $fileName
cat $temp | cat >> $fileName
rm $temp
echo "Enter Name"
read name
echo "Enter Phone Number of $name"
read number
echo "Enter Address of $name"
read address
echo "$name\t\t$number\t$address" | cat >> $fileName
;;
esac
done
