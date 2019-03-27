
<?php
if (file_exists("/home/pi/liste.csv"))
{
echo "Le fichier existe" . "<br />\n";
}
else
{
echo "Fichier inexistant";
}
echo "          numero carte, date et heure". "<br />\n";

$ligne = 1; // compteur de ligne
$fic = fopen("/home/pi/liste.csv", "r");
while($tab=fgetcsv($fic,1024,';'))
{
$champs = count($tab);//nombre de champ dans la ligne en question
echo " entrée " . $ligne . " : ";
$ligne ++;
//affichage de chaque champ de la ligne en question
for($i=0; $i<$champs; $i ++)
{
echo $tab[$i] . "". "<br />\n";
}
}
?>
