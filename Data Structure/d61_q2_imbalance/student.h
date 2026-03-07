// Your code here
size_t find_hight(node* m, size_t &bestbst, KeyT &k){
    if(m == NULL) return 0;

    size_t left = find_hight(m->left, bestbst, k);
    size_t right = find_hight(m->right, bestbst, k);

    size_t diff = left > right ? left - right : right - left;

    if(diff > bestbst || (diff == bestbst && m->data.first < k)){
        bestbst = diff;
        k = m->data.first;
    }

    return 1 + (left > right ? left : right);
}

KeyT getValueOfMostImbalanceNode() {
    // Your code here
    if(mRoot == NULL) return KeyT();

    KeyT k = mRoot->data.first;
    
    size_t bestbst = 0;
    find_hight(mRoot, bestbst, k);
    return k;
}



