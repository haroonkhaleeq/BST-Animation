// AVLView.cpp : implementation of the CAVLView class
//

#include "stdafx.h"
#include "AVL.h"

#include <stdlib.h>
#include <time.h>

#include "AVLDoc.h"
#include "AVLView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


template <class T>
class Stack
{
	private:
		T *data;
		int capacity;
		int top;
	
	public:
		Stack(int size);
		void push(T value);
		T pop();
		T stackTop();
		int getTop();
		int isEmpty();
		int isFull();

};

class Pair
{
	public:
		int x,y,r;
		Pair()
		{
			x=0;
			y=0;
			r=0;
		}
		Pair(int a , int b, int c)
		{
			x=a;
			y=b;
			r=c;
		}
};

template <class T>
class Node 
{
	public:
		int LH;
		int RH;
		T info;
		Node<T> *left;
		Node<T> *right;
		Node();
		Node(T val);
};

template <class T>
class AVL
{	
	Node<T> *root;
	void inOrder(Node<T> *p);
	
	public:
		AVL()
		{
			root=0;
		}
		Node<T>* search(T key,Stack<Node<T>*> &obj);
		Node<T>* searchParent(T key);
		void search(T key,int x, int y, CDC* pDC);
		void insert(T key,int x, int y,CDC* pDC);
		void remove(T key);
		void inOrder();
		int getHeight(Node<T> *p);
		void balanceTree(Stack<Node<T>*> &obj, Stack<Pair> &S, CDC* pDC);

};


/////////////////////////////////////////////////////////////////////////////
// CAVLView

IMPLEMENT_DYNCREATE(CAVLView, CView)

BEGIN_MESSAGE_MAP(CAVLView, CView)
	//{{AFX_MSG_MAP(CAVLView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAVLView construction/destruction

CAVLView::CAVLView()
{
	// TODO: add construction code here

}

CAVLView::~CAVLView()
{
}

BOOL CAVLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CAVLView drawing

void CAVLView::OnDraw(CDC* pDC)
{
	CAVLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	
	CBrush b1(RGB(0, 125, 5));//green
	CBrush b2(RGB(255, 2, 5));//red
	CBrush b3(RGB(250, 255, 5));//yellow
	CBrush b4(RGB(0, 2, 255));//blue		
	
	
	int x=400,y=50;

	
	AVL<int> obj;

	obj.insert(6,x,y,pDC);
	obj.insert(3,x,y,pDC);
	obj.insert(9,x,y,pDC);
	obj.insert(7,x,y,pDC);
	obj.insert(169,x,y,pDC);
	obj.insert(5,x,y,pDC);
	obj.insert(2,x,y,pDC);

	obj.search(7,x,y,pDC);
	obj.search(1,x,y,pDC);
			
}

/////////////////////////////////////////////////////////////////////////////
// CAVLView printing

BOOL CAVLView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAVLView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CAVLView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CAVLView diagnostics

#ifdef _DEBUG
void CAVLView::AssertValid() const
{
	CView::AssertValid();
}

void CAVLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAVLDoc* CAVLView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAVLDoc)));
	return (CAVLDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAVLView message handlers

template <class T>
Node<T>::Node()
{
	right=left=0;
}

template <class T>
Node<T>::Node(T val)
{
	info = val;
	right=left=0;
}

template <class T>
void AVL<T>::insert(T key,int x, int y,CDC* pDC)
{
	Node<T> *p = root;
	Stack<Node<T>*> obj(30);
	Stack<Pair> S(30);
	int r = 60;
	int x1=x,y1=y;
	
	int t=0;
	while(p!=0)
	{
		obj.push(p);
		Pair o(x1,y1,r);
		S.push(o);

		if(p->info > key)
		{
			if(p->left)
			{
				x = x-r;
				y = y+40;
				r = r - 20;
				p=p->left;
			}
			else
			{	
				clock_t start_time;
				start_time = clock();
			    while((clock() - start_time) < 0.49 * CLOCKS_PER_SEC)
				{
        
				}
				
				CBrush b1(RGB(0, 125, 5));//green
				CBrush b3(RGB(250, 255, 5));//yellow
				char ar[10];
				itoa(key,ar,10);
				
				pDC->SelectObject(b1);					//left sub-tree
				pDC->MoveTo(x,y);		
				pDC->LineTo(x-r,y+40);
				pDC->SelectObject(b3);
				pDC->Ellipse(x-r-15,y+40-15,x-r+15,y+40+15);
				pDC->TextOut(x-r-8,y+40-8,ar);

				p->left = new Node<T>(key);
				t=1;
				break;
			}
		}
		else
		{
			if(p->right)
			{
				x = x+r;
				y = y+40;
				r = r - 20;

				p=p->right;
			}
			else
			{
				clock_t start_time;
				start_time = clock();
			    while((clock() - start_time) < 0.49 * CLOCKS_PER_SEC)
				{
        
				}
				
				CBrush b1(RGB(0, 125, 5));//green
				CBrush b3(RGB(250, 255, 5));//yellow
				char ar[10];
				itoa(key,ar,10);

				pDC->SelectObject(b1);					//right sub-tree
				pDC->MoveTo(x,y);		
				pDC->LineTo(x+r,y+40);
				pDC->SelectObject(b3);
				pDC->Ellipse(x+r-15,y+40-15,x+r+15,y+40+15);
				pDC->TextOut(x+r-8,y+40-8,ar);

				p->right = new Node<T>(key);
				t=1;
				break;
			}
		}
	
	}

	if(t==0)
	{
		root = new Node <T>(key);

		CBrush b3(RGB(250, 255, 5));//yellow
		char ar[10];
		itoa(key,ar,10);
		pDC->SelectObject(b3);					// Node
		pDC->Ellipse(x-15,y-15,x+15,y+15);
		pDC->TextOut(x-8,y-8,ar);
	}

	getHeight(root);

	//balanceTree(obj,S,pDC);
			
}

template <class T>
Node<T>* AVL<T>::searchParent(T key)
{
	Node<T> *p = root;

	while(p!=0)
	{
		if(p->left)
		{
			if(p->left->info==key)
				return p;
		}
		else if(p->right)
		{
			if(p->right->info==key)
				return p;
		}

		if(p->info > key)
			p=p->left;
		else
			p=p->right;
	}

	return 0;
}

template <class T>
Node<T>* AVL<T>::search(T key,Stack<Node<T>*> &obj)
{
	Node<T> *p = root;

	while(p!=0 && p->info!=key)
	{
		obj.push(p);

		if(p->info > key)
			p=p->left;
		else
			p=p->right;
	}

	if(p)
		return p;
	else
		return 0;
}

template <class T>
void AVL<T>::search(T key, int x, int y, CDC* pDC)
{
	Node<T> *p = root;
	int r = 60;	
	
	CBrush b1(RGB(0, 125, 5));//green
	CBrush b2(RGB(255, 2, 5));//red

	char ar[10], ar2[10];
	itoa(p->info,ar,10);
			
	clock_t start_time;
	start_time = clock();
    while((clock() - start_time) < 0.49 * CLOCKS_PER_SEC)
	{
      
	}
	
	pDC->MoveTo(x,y);
	pDC->SelectObject(b1);
	pDC->Ellipse(x-15,y-15,x+15,y+15);
	pDC->TextOut(x-8,y-8,ar);

	while(p!=0 && p->info!=key)
	{
		if(p->info > key)
		{
			itoa(p->info,ar2,10);

			p=p->left;
			
			if(p==0)
				break;
			
			
			char ar[10];
			itoa(p->info,ar,10);
						
			clock_t start_time;
			start_time = clock();
			while((clock() - start_time) < 0.49 * CLOCKS_PER_SEC)
			{
      
			}

			
			pDC->MoveTo(x,y);
			pDC->SelectObject(b1);
			pDC->Ellipse(x-r-15,y+40-15,x-r+15,y+40+15);
			pDC->TextOut(x-r-8,y+40-8,ar);

			
			x = x-r;
			y = y+40;
			r = r - 20;
					
		}
		else
		{
			itoa(p->info,ar2,10);

			p=p->right;
		
			if(p==0)
				break;

			char ar[10];
			itoa(p->info,ar,10);
			
			clock_t start_time;
			start_time = clock();
			while((clock() - start_time) < 0.49 * CLOCKS_PER_SEC)
			{
      
			}
			
			
			pDC->MoveTo(x,y);
			pDC->SelectObject(b1);
			pDC->Ellipse(x+r-15,y+40-15,x+r+15,y+40+15);
			pDC->TextOut(x+r-8,y+40-8,ar);
			
			
			x = x+r;
			y = y+40;
			r = r - 20;
			
		}
	}

	if(!p)
	{
		pDC->SelectObject(b2);
		pDC->Ellipse(x-15,y-15,x+15,y+15);
		pDC->TextOut(x-8,y-8,ar2);
	}
	
}


template <class T>
void AVL<T>::inOrder(Node<T> *p)
{
	if(p==0)
		return;

	inOrder(p->left);
	
	cout<<p->info;

	inOrder(p->right);
}

template <class T>
void AVL<T>::inOrder()
{
	inOrder(root);
}

template <class T>
void AVL<T>::remove(T key)
{

	Stack<Node<T>*> obj(30);
	
	Node<T> *p = search(key,obj);
	Node<T> *par = searchParent(key);

	if(p==0)
		return;
	
	if(p != 0 && par == 0)
	{
			// root case for deletion			
	}
	
	if(p->left==0 && p->right==0)
	{
		delete p;
		
		if(par->left==p)
			par->left=0;
		else
			par->right=0;
		
	}
	else if((p->left==0 && p->right!=0) || (p->right==0 && p->left!=0))
	{
		if(par->left==p)
		{
			if(p->left)
				par->left = p->left;
			else
				par->left = p->right;
		}
		else
		{
			if(p->right)
				par->right = p->right;
			else
				par->right = p->left;
		}

	}
	else if(p->left!=0 && p->right!=0)
	{
		Node<T> *spar = p->right;
		
		Node<T> *succ=0;

		if(p->right->left)
		{
			succ = p->right->left;

			while(succ->left!=0)
			{
				succ = succ->left;
				spar = spar->left;
			}

			p->info = succ->info;
			delete succ;
			spar->left = NULL;
		}
		else
		{
			p->info = p->right->info;
			delete p->right;
			p->right=NULL;
			return;
		}
	
	}

	getHeight(root);

	balanceTree(obj);

}

template <class T>
int AVL<T>::getHeight(Node<T> *p)
{
	if(p==0)
		return 0;

	if(p->left)
		p->LH = getHeight(p->left);
	else
		p->LH = 0;

	if(p->right)
		p->RH = getHeight(p->right);
	else
		p->RH = 0;

	if(p->LH > p->RH)
		return p->LH+1;
	else
		return p->RH+1;
}


template <class T>
void AVL<T>::balanceTree(Stack<Node<T>*> &obj, Stack<Pair> &S, CDC* pDC)
{
	Node<T> *q=0;
	Node<T> *p=0;
	Pair A;
	CBrush b3(RGB(250, 255, 5));//yellow
	CBrush b1(RGB(0, 125, 5));//green

	int t=0, bf=0;
	while(!obj.isEmpty())
	{
		q = p;
		p = obj.pop();
		A = S.pop();

		bf = p->LH - p->RH;

		if(bf>1 || bf<-1)
		{
			t=1;
			break;
		}

	}

	if(t==0)
		return;

	int bf2 = q->LH - q->RH;

	if(bf>0)
	{
		if(bf2>0)		// LL
		{
			Node<T> *l = obj.pop();
			Node<T> *RLP = q->right;
			int x=A.x, y=A.y, r=A.r;

			char ar[10];
			itoa(q->info,ar,10);

				clock_t start_time;
				start_time = clock();
			    while((clock() - start_time) < 0.49 * CLOCKS_PER_SEC)
				{
        
				}
			
				pDC->MoveTo(x,y);		
				pDC->TextOut(x-r-8,y+40-8,ar);

				start_time = clock();
			    while((clock() - start_time) < 0.49 * CLOCKS_PER_SEC)
				{
        
				}
			
			pDC->SelectObject(b1);
			pDC->MoveTo(x,y);		
			pDC->LineTo(x-r,y+40);
			pDC->SelectObject(b3);
			pDC->Ellipse(x-r-15,y+40-15,x-r+15,y+40+15);
			itoa(p->info,ar,10);
			pDC->TextOut(x-r-8,y+40-8,ar);

			x+=r;
			y+=40;
			r-=20;

			q->right = p;
			p->left = RLP;

			if(l->left == p)
				l->left = q;
			else
				l->right = q;

		}
		else			// LR
		{
			Node<T> *l = obj.pop();	
			Node<T> *RLP = q->right;

			Node<T> *RRLP = RLP->right;
			Node<T> *LRLP = RLP->left;
			
			RLP->left = q;
			RLP->right = p;
			q->right = LRLP;
			p->left = RRLP;

			if(l->left == p)
				l->left = RLP;
			else
				l->right = RLP;


		}
	}
	else
	{
		if(bf2>0)		// RL
		{
			Node<T> *l = obj.pop();	
			Node<T> *LRP = q->left;

			p->right = LRP->left;
			q->left = LRP->right;
			LRP->left = p;
			LRP->right = q;

			if(l->right == p)
				l->right = LRP;
			else
				l->left = LRP;
		
		}
		else			// RR
		{
			Node<T> *l = obj.pop();	
			Node<T> *RRP = q->left;	

			q->left = p;
			p->right = RRP;

			if(l->left == p)
				l->left = q;
			else
				l->right = q;

		}

	}

		

}


template <class T>
Stack<T>::Stack(int size)
{
	data = new T [size];

	capacity = size;

	top = 0;
}

template <class T>
void Stack<T>::push(T value)
{
	if(!isFull())
	{
		data[top] = value;
		top++;
	}
	else
	{
		exit(0);
	}
}

template <class T>
T Stack<T>::pop()
{
	if(!isEmpty())
	{
		top--;
		return data[top];
	}

	exit(0);
}

template <class T>
T Stack<T>::stackTop()
{
	return data[top-1];
}

template <class T>
int Stack<T>::getTop()
{
	return top;
}

template <class T>
int Stack<T>::isEmpty()
{
	if(top==0)
		return 1;

	return 0;
}

template <class T>
int Stack<T>::isFull()
{
	if(top==capacity)
		return 1;

	return 0;
}

