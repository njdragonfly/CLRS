/*
Copyright 2009 http://code.google.com/p/intro2algorithms/. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:
  * Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
  * Redistributions in binary form must reproduce the above
    copyright notice, this list of conditions and the following
    disclaimer in the documentation and/or other materials provided
    with the distribution.
  * Neither the name of http://code.google.com/p/intro2algorithms/ nor the names of its
    contributors may be used to endorse or promote products derived
    from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/*Solution to the Excise 10.2-8 of Introduction to Algorithms*/

template <typename T>
class dLinkList {
private:
	class Node {
	public:
		T item;
		int np;
		Node() {
			np=0;
		}
	};
	Node * head;
	Node * curr;
	Node * pre;
	Node * tail;
	int _size;

public:
	void next() {
		Node * t;
		t=(Node*)((int)curr->np^(int)pre);
		pre=curr;
		curr=t;
	}

	void prev() {
		Node * t;
		t=(Node*)((int)pre->np^(int)curr);
		curr=pre;
		pre=t;
	}

	T value() {
		return curr->item;
	}

	void insertvalue(const T & v) {
		_size++;
		if(head==0) {
			head=new Node();
			head->item=v;
			curr=head;
			pre=0;
		} else {
			Node * t=new Node();
			t->item=v;
			curr->np=(int)pre^(int)t;
			pre=curr;
			curr=t;
			curr->np=(int)pre^0;
		}
		tail=curr;
	}

	void reverse() {
		Node * t;
		t=head;
		head=tail;
		tail=t;
		pre=(Node*)((int)pre^(int)curr->np);
	}

	int size() {
		return _size;
	}

	dLinkList() {
		head=0;
		curr=0;
		pre=0;
		tail=0;
		_size=0;
	}

	~dLinkList() {
		pre=0;
		while(_size) {
			curr=head;
			head=(Node*)((int)pre^(int)curr->np);
			pre=curr;
			delete curr;
			_size--;
		}
	}
};

