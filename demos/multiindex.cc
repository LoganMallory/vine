const int DEBUG   = 1;
const int OPT_LVL = 0;
#include "../Vine.h"

//this program shows how the RefArray class can be used to index and set/get data from a Vine
int main() {
  //create a Vine with 10 values set to 5
  Vine<int> vec1(5, 10);
  vec1.print();

  /* Numeric Indexing */
  //create an array numeric_indexes_vec for indexing vec1 at indexes 0, 1, 3
  //TODO: make this list initialization once that is implemented
  Vine<unsigned int> numeric_indexes_vec(3);
  numeric_indexes_vec[0] = 0;
  numeric_indexes_vec[1] = 1;
  numeric_indexes_vec[2] = 3;
  numeric_indexes_vec.print();  //[ 0   1   3   ]

  //Option 1 - pass the index vector to the [] operator
  //(which subsequently returns a RefArray, which then takes 3 as the arg to RefArray::operator= and assigns 3 to the appropiate indexes)
  vec1[numeric_indexes_vec] = 3;

  //Option 2 - create the RefArray explicitly (bad style though - please don't do this)
  RefArray<int> rarr1 = vec1[numeric_indexes_vec];
  rarr1 = 3;

  //print vec1 again to show that 3 was assigned at the correct indexes (0, 1, 3)
                  //         0   1       3
  vec1.print();   //prints [ 3   3   5   3   5   5   5   5   5   5   ]

  /* Boolean Indexing */
  Vine<bool> boolean_indexes_vec = vec1 >= 4; //get boolean vector where vec1 >= 4
  boolean_indexes_vec.print(); //[ 0   0   1   0   1   1   1   1   1   1   ]

  //Option 1 - pass the boolean vector to the [] operator
  //(which subsequently returns a RefArray with pointers only for the true indxexes, which then takes 9 as the arg to RefArray::operator= and assigns 9 to the appropiate indexes)
  vec1[boolean_indexes_vec] = 9;

  //Option 2 - create the RefArray explicitly (bad style though - please don't do this)
  RefArray<int> rarr2 = vec1[boolean_indexes_vec];
  rarr2 = 9;

  //print vec1 again to show that 9 was assigned at the correct indexes (2, 4, 5, 6, 7, 8, 9)
                //          2       4   5   6   7   8   9
  vec1.print(); //[ 3   3   9   3   9   9   9   9   9   9   ]

  return 0;
}
