function contentDisplayer
{
for i  in $1/*;
do
if [[ -d $i && ! -h $i ]];
then
echo $i;
contentDisplayer $i
else
echo $i;
fi;
done
}
contentDisplayer $1
