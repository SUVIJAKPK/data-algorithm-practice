void shift(int k) {
	// TODO: Add your code here
	if(mSize <= 0) return;
	int left = k % (int)mSize;
	int sum_left = (left < 0) ? (left + mSize) : left;

	node* inf = mHeader->next;
	while(sum_left--){
		inf = inf->next;
	}

	//เชื่อม Loop
	mHeader->next->prev = mHeader->prev;
	mHeader->prev->next = mHeader->next;  

	//ต่อ mHeader
	mHeader->prev = inf->prev;
	inf->prev->next = mHeader;

	mHeader->next = inf;
	inf->prev = mHeader;
}
