#include "ArrayList.h"
 template<class ItemType> 
 ArrayList<ItemType>::ArrayList(){
    itemCount = 0;
    maxCount = DEFAULT_CAPACITY;
}

 template<class ItemType> 
 int ArrayList<ItemType>::getLength() const{
    return itemCount;
}
     
 template<class ItemType> 
 bool ArrayList<ItemType>::isEmpty() const{
    return itemCount == 0;
}

 template<class ItemType> 
 bool ArrayList<ItemType>::insert(int newPos, const ItemType& newEntry){
    bool canInsert = itemCount < maxCount && newPos >= 1 && newPos <= itemCount + 1;
     if(canInsert){
         
        for(int pos = itemCount; pos >= newPos; pos--){
            items[pos + 1] = items[pos];
        }

        items[newPos] = newEntry;
        itemCount++;
     }
     return canInsert;
 }

  template<class ItemType> 
 ItemType ArrayList<ItemType>::getEntry(int position) const{
     bool canGet = position >= 1 && position <= itemCount;
     if(canGet){
         return items[position];
     }
     else{
         throw "invalid position";
     }
 }

  template<class ItemType> 
 ItemType ArrayList<ItemType>::replace(int position, 
                                       const ItemType& newEntry){
     bool canReplace = position >= 1 && position <= itemCount;
     if(canReplace){
         ItemType oldEntry = items[position];
         items[position] = newEntry;
         return oldEntry;
     }
     else{
         throw "invalid position";
     }
 }

  template<class ItemType> 
 bool ArrayList<ItemType>::remove(int position){
     bool canRemove = position >= 1 && position <= itemCount; 
     if(canRemove){
         for(int pos = position; pos < itemCount; pos++){
             items[pos] = items[pos + 1];
         }
         itemCount--;
     } 
  
     return canRemove;
 }

  template<class ItemType> 
 void ArrayList<ItemType>::clear(){
     itemCount = 0;
 }