BSNode<T>* n = root();
BSNode<T>* par = nullptr;

while(n != nullptr){
	if(obj < n->retrieve()){
		par = n;
		n = n->left();
	}	
	else if(obj > n->retrieve()){
		par = n;
		n = n->right();
	}
	else{
		if(n->left() == nullptr || n->right() == nullptr){
			BSNode<T>* child = (n->left() != nullptr) ? n->left() : n->right();
			if(par == nullptr){
				root() = child;
			}
			else if (par->left() == n){
				par->left() = child;
			}
			else{
				par->right() = child;
			}
			delete n;
			return;
		}
		else {
    			BSNode<T>* succPar = n;
    			BSNode<T>* succ = n->right();

    			while (succ->left() != nullptr) {
        			succPar = succ;
        			succ = succ->left();
    			}

    			n->setValue(succ->retrieve());

    			BSNode<T>* succChild = succ->right();
    			if (succPar->left() == succ){
        			succPar->left() = succChild;
			}
    			else{
        			succPar->right() = succChild;
			}

    			delete succ;
    			return;
		}
	}
}
