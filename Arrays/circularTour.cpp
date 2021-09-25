//https://practice.geeksforgeeks.org/problems/circular-tour/1#
//Simple But Tricky 
int tour(petrolPump p[], int n){
   int i = 0, j = 0;
   int backup = 0;

   while (i < n) {

      backup = p[j].petrol - p[j].distance + backup;

      if ((j + 1) % n == i && backup >= 0)
         return i;

      if (backup >= 0)
         j = (j + 1) % n;
      else{
         if (j < i)
            return -1;
         i = j + 1;
         j = i;
         backup = 0;
      }
   }
   return -1;
}
