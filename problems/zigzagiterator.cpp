#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class ZigzagIterator {
private:
    vector<int>::iterator _it1;
    vector<int>::iterator _it2;
    vector<int> _v1;
    vector<int> _v2;
    bool _order;
    int updateState(vector<int>::iterator &it, bool &order){
        int ret = *it;
        order = !order;
        it++;
        return ret;
    }
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        _v1 = v1;
        _v2 = v2;
        _it1 = _v1.begin();
        _it2 = _v2.begin();
        _order = true;
    }

    int next() {
        assert(hasNext());
        if(_it1 != _v1.end() && _it2 != _v2.end()){
            if(_order){
                return updateState(_it1, _order);
            }
            else{
                return updateState(_it2, _order);
            }
        }
        else{
            if(_it1 != _v1.end()){
                return updateState(_it1, _order);
            }
            else{
                return updateState(_it2, _order);
            }
        }
        
    }

    bool hasNext() {
        return (_it1 != _v1.end() || _it2 != _v2.end());
    }
};

int main(int argc, char* argv[]){
    vector<int> v1 = {1, 2, 3, 4};
    vector<int> v2 = {5, 6, 7, 8};
    ZigzagIterator i(v1, v2);
    while (i.hasNext()) cout << i.next();
    cout<<endl;
}
