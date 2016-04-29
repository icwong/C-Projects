/* File: char_stack.h       

  Header file for a very basic array-based implementation of a stack.

*/
class char_stack
{
  public:
    char_stack();
    void push( char item );
    char pop(); 
    char top();
    bool empty();
    int size();

  private:
    static const int capacity = 250000;//the array size, at most 250 characters per line
    char A[capacity] ;//the array.
    int top_index ; // this will index the top of the stack in the array
};

