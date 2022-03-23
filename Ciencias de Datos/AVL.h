#include<iostream>
using namespace std;

struct node{
    int clave;
    int fb;
    node* izq;
    node* der;
};

class avl{
	node* cab;
	public:
		avl(){
        	cab = NULL;
    	}
    	void insertar(int x){
        	cab = insertar(x, cab);
    	}

    	void eliminar(int x){
        	cab = eliminar(x, cab);
    	}
    	
    	void imprimir(){
    		cout<<endl<<"Inorden: "<<endl;
		    inorder(cab);	
		    cout<<endl<<"Preorden: "<<endl;
		    preorden(cab);	
		    cout<<endl<<"Posorden: "<<endl;
		    posorden(cab);	
		    cout<<endl;
    	}
    
    void vacio(node* t);
    node* insertar(int x, node* t);
    node* sencillaDer(node* &t);
    node* sencillaIzq(node* &t);
    node* dobleIzq(node* &t);
    node* dobleDer(node* &t);
    node* menor(node* t);
    node* mayor(node* t);
    node* eliminar(int x, node* t);
    int facB(node* t);
    int balance(node* t);
    void inorder(node* t);   	  
	void preorden(node* t);   
	void posorden(node* t); 
};

void avl::vacio(node* t){
    if(t == NULL)
        return;
    vacio(t->izq);
    vacio(t->der);
    delete t;
}

node* avl::insertar(int x, node* t){
	if(t == NULL){
        t = new node;
        t->clave = x;
        t->fb = 0;
        t->izq = t->der = NULL;
    }
    else if(x < t->clave){
        t->izq = insertar(x, t->izq);
        if(facB(t->izq) - facB(t->der) == 2)
        {
            if(x < t->izq->clave)
                t = sencillaDer(t);
            else
                t = dobleDer(t);
        }
    }
    else if(x > t->clave){
        t->der = insertar(x, t->der);
        if(facB(t->der) - facB(t->izq) == 2)
        {
            if(x > t->der->clave)
                t = sencillaIzq(t);
            else
                t = dobleIzq(t);
        }
    }
    t->fb = max(facB(t->izq), facB(t->der))+1;
    return t;
}

node* avl::sencillaDer(node* &t){
	node* u = t->izq;
    t->izq = u->der;
    u->der = t;
    t->fb = max(facB(t->izq), facB(t->der))+1;
    u->fb = max(facB(u->izq), t->fb)+1;
    return u;
}

node* avl::sencillaIzq(node* &t){
	node* u = t->der;
    t->der = u->izq;
    u->izq = t;
    t->fb = max(facB(t->izq), facB(t->der))+1;
    u->fb = max(facB(t->der), t->fb)+1 ;
    return u;
}

node* avl::dobleIzq(node* &t){
	t->der = sencillaDer(t->der);
    return sencillaIzq(t);
}

node* avl::dobleDer(node* &t){
	t->izq = sencillaIzq(t->izq);
    return sencillaDer(t);
}

node* avl::menor(node* t){
	if(t == NULL)
        return NULL;
    else if(t->izq == NULL)
        return t;
    else
        return menor(t->izq);
}

node* avl::mayor(node* t){
	if(t == NULL)
        return NULL;
    else if(t->der == NULL)
        return t;
    else
        return mayor(t->der);
}

node* avl::eliminar(int x, node* t){
	node* temp;

    if(t == NULL)
        return NULL;
    else if(x < t->clave)
        t->izq = eliminar(x, t->izq);
    else if(x > t->clave)
        t->der = eliminar(x, t->der);
    else if(t->izq && t->der){
        temp = menor(t->der);
        t->clave = temp->clave;
        t->der = eliminar(t->clave, t->der);
    }
    else{
        temp = t;
        if(t->izq == NULL)
            t = t->der;
        else if(t->der == NULL)
            t = t->izq;
        delete temp;
    }
    if(t == NULL)
        return t;
    t->fb = max(facB(t->izq), facB(t->der))+1;
    
    if(facB(t->izq) - facB(t->der) == 2){
        if(facB(t->izq->izq) - facB(t->izq->der) == 1)
            return sencillaIzq(t);
        else
            return dobleIzq(t);
    }
    else if(facB(t->der) - facB(t->izq) == 2){
        if(facB(t->der->der) - facB(t->der->izq) == 1)
            return sencillaDer(t);
        else
            return dobleDer(t);
    }
    return t;
}

int avl::facB(node* t){
	return (t == NULL ? -1 : t->fb);
}

int avl::balance(node* t){
	if(t == NULL){
		return 0;
	}
    else{
    	return facB(t->izq) - facB(t->der);
	}
}

void avl::inorder(node* t){
	if(t == NULL)
        return;
    inorder(t->izq);
    cout<<t->clave<< " ";
    inorder(t->der);
}

void avl::preorden(node* t){
	if(t == NULL)
        return;
    cout<<t->clave<< " ";
    preorden(t->izq);
    preorden(t->der);
}

void avl::posorden(node* t){
	if(t == NULL)
        return;
    posorden(t->izq);
    posorden(t->der);
    cout<<t->clave<< " ";   
}
