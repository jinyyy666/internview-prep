// My version of queue using array:
#include <iostream>

Class My_Queue{
 private:
  int _in;
  int _out;
  int _size;
  int * _q_arr;
 public:
  // initialization:
 My_Queue(int size):
  _in(0), 
  _out(0), 
  _size(size)
  { if(_size > 0)
      _q_arr = new int[size];
    else{
      std::cerr<<"Invaild size for the queue!"<<std::endl;
      std::cerr<<"Exitting!"<<endl;
    }
  }
  ~My_Queue(){ 
    delete _q_arr;
    _q_arr = NULL;
  }

  int Enqueue(int a){
    // if the queue is full
    if( _in == (_out -1 + _size) % _size)
      return -1; // failure
    
    _q_arr[_in] = a;
    _in = (_in + 1) % _size;
    
    return 0;  // success
  } 
  int Dequeue(int * old){
    // if the queue is empty
    if(_in == _out)
      return -1;
    
    *old = _q_array[_out];
    _out = (_out + 1) % _size;
      
    return 0;
  }

};
