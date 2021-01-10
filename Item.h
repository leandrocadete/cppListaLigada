#ifndef ITEM_H

template <class TItem>
class Item {
public:
    Item() {}
    ~Item() { 
        //cout << "Destructor Item" << endl; 
    }
    Item* ptrProximo;
    TItem item;
};

#endif