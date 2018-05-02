#include "Binary_Search_Tree.h"

template<typename Item_Type>
class Morse_Tree : public Binary_Search_Tree<Item_Type>{
private:
	bool insert(BTNode<Item_Type>*& local_root, const Item_Type& item);
};

template<typename Item_Type>
inline bool Morse_Tree<Item_Type>::insert(BTNode<Item_Type>*& local_root, const Item_Type & item)
{
	if (local_root == NULL) {
		local_root = new BTNode<Item_Type>(item);
		return true;
	}
	else {
		if (item < local_root->data && item[1] == '.')
			return insert(local_root->left, item);
		else if (local_root->data < item && item[1] == '_')
			return insert(local_root->right, item);
		else
			return false;
	}
}


template<typename Item_Type>
inline bool Morse_Tree<Item_Type>::insert(BTNode<Item_Type>*& local_root, const Item_Type & item) 
{
	
	BTNode<Item_Type> temp;
	for (int i = 0; i < item.size(); i++) {
		if ((item[i] == ".") && (item[i] != item.end()) {
			if (local_root->left->data == NULL) {

			}
		}
	}
}
//template<typename Item_Type>
//bool Binary_Search_Tree<Item_Type>::insert(BTNode<Item_Type>*& local_root, const Item_Type& item) {
//	if (local_root == NULL) {
//		local_root = new BTNode<Item_Type>(item);
//		return true;
//	}
//	else {
//		if (item > local_root->data)
//			return insert(local_root->left, item);
//		else if (local_root->data > item)
//			return insert(local_root->right, item);
//		else
//			return false;
//	}
//}