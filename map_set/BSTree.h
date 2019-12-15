#include<iostream>
using namespace std;

template<class k>

struct BSTreeNode
{
	BSTreeNode<k>* _left;
	BSTreeNode<k>* _right;
	k _key;

	BSTreeNode(const k& key)	
		:_key(key)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template<class k>
class BSTree
{ 
	typedef BSTreeNode<k> Node;
public:
	BSTree()
		:_root(nullptr)
	{}

	~BSTree()
	{

	}

	bool Insert(const k& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key>key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key);
		if (parent->_key < key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	 }

	Node* Find(const k& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key>key)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}
		return nullptr;
	}

	bool Erase(const k& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;

		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key>key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else//走到这表示找到了
			{
				//分为三种情况
				//1.左为空
				//2.右为空
				//3.左右都不为空
				Node* del = cur;
				if (cur->_left == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
				}
				else if (cur->_right == nullptr)
				{
					if (parent->_left == cur)
					{
						parent->_left = cur->_left;
					}
					else
					{
						parent->_right = cur->_left;
					}
				}
				else
				{
			
					Node* lessparent = cur;
					Node* rightLess = cur->_right;
					while (rightLess->_left)
					{
						lessparent = rightLess;
						rightLess = rightLess->_left;
					}
					cur->_key = rightLess->_key;
					del = rightLess;
					if (lessparent->_left == rightLess)
					{
						lessparent->_left = rightLess->_right;
					}
					else
					{
						lessparent->_right = rightLess->_right;
					}
				}
				delete del;
				return true;
			}
		}
		return false;
	}

	void inOrder()
	{
		_inOrder(_root);
		cout << endl;
	}

	void _inOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_inOrder(root->_left);
		cout << root->_key << " ";
		_inOrder(root->_right);
	}

	//递归版本实现

	bool InsertR(const k& key)
	{
		return _Insert(_root, key);
	}

	bool _Insert(Node* & root, const k& key)
	{
		if (root == nullptr)
			root = new Node(key);

		if (root->_key < key)
		{
			return _Insert(root = root->_right,key);
		}
		else if (root->_key>key)
		{
			return _Insert(root = root->_left, key);
		}
		else
		{
			return false;
		}
	}

	Node* FindR(const k& key)
	{
		return _FindR(root->_key, key);
	}

	Node* _FindR(Node* root, const k& key)
	{
		if (root == nullptr)
			return nullptr;

		if (root->_key == key)
		{
			return root;
		}
		else if (root->_key < key)
		{
			return _FindR(root->_right, key);
		}
		else
		{
			return _FindR(root->_left, key);
		}
	}

	//bool EraseR( const k& key)
	//{
	//	//Node* root=_root;
	//	return _EraseR(root->_key, key);
	//}

	//bool _EraseR(Node* root, const k& key)
	//{
	//	if (root == nullptr)
	//		return false;

	//	Node* cur = root;
	//	Node* parent = cur;
	//	

	//	if (cur->_key < key)
	//	{
	//		parent = cur;
	//		return _EraseR(cur->_right,key);
	//	}
	//	else if (cur->_key>key)
	//	{
	//		parent = cur;
	//		return _EraseR(cur->_left, key);
	//	}
	//	else
	//	{
	//		//分为三种情况
	//		//1、左为空
	//		//2、右为空
	//		//3.左右都不为空
 //            Node* del=cur;
	//		 if (cur->_left == nullptr)
	//		{
	//			 if (parent == nullptr)
	//			 {
	//				 root = cur->_right;
	//			 }
	//			 else
	//			 {
	//				 if (parent->_left == cur)
	//				 {
	//					 parent->_left = cur->_right;
	//				 }
	//				 else
	//				 {
	//					 parent->_right = cur->_right;
	//				 }
	//			 }
	//		}
	//		 else if (cur->_right==nullptr)
	//		 {
	//			 if (parent == nullptr)
	//			 {
	//				 root = cur->_left;
	//			 }
	//			 else
	//			 {
	//				 if (parent->_left == cur)
	//				 {
	//					 parent->_left = cur->_left;
	//				 }
	//				 else
	//				 {
	//					 parent->_right = cur->_left;
	//				 }
	//			 }
	//		 }
	//		 else
	//		 {
	//			 Node* Lessparent = nullptr;
	//			 Node* Lessright = cur->_right;
	//			 while (Lessright->_left)
	//			 {
	//				 Lessparent = Lessright;
	//				 Lessright = Lessright->_left;

	//			 }
	//			 cur->_key = Lessright->_key;
	//			 del = Lessright;
	//			 if (Lessparent->_left == Lessright)
	//			 {
	//				 Lessparent->_left = Lessright->_right;
	//			 }
	//			 else
	//			 {
	//				 Lessparent->_right = Lessright->_right;
	//			 }
	//		 }
	//		 delete del;
	//		 return true;
	//	}
	//}
private:
	Node* _root;
};

void TestBSTree()
{
	int a[] = {5,3,4,1,7,8,2,6,0,9 };
	BSTree<int> t;
	for (auto e : a)
	{
		t.Insert(e);
	}

	t.inOrder();
	t.Erase(2);
	t.Erase(8);
	t.Erase(1);
	t.Erase(7);
	t.Erase(5);
	t.inOrder();
}