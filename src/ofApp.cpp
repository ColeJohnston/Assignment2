#include "ofApp.h"
#include <iostream>



struct Node {
	int data;
	Node* next;
	Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
	Node* head;
	LinkedList() : head(nullptr) {}

	void insertAtHead(int value) {
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
	}

	void insertAtTail(int value) {
		Node* newNode = new Node(value);
		if (!head) {
			head = newNode;
			return;
		}
		Node* temp = head;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = newNode;
	}

	void deleteFromHead() {
		if (!head) return;
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	void deleteFromTail() {
		if (!head) return;
		if (!head->next) {
			delete head;
			head = nullptr;
			return;
		}
		Node* temp = head;
		while (temp->next->next) {
			temp = temp->next;
		}
		delete temp->next;
		temp->next = nullptr;
	}

};

LinkedList linkedList;
float activeTime = 0;
float amplitude = 50;
array<int, 2> cameraPosition = { 0,0 };
//--------------------------------------------------------------
void ofApp::setup() {

}

//--------------------------------------------------------------
void ofApp::update() {
	activeTime += 0.05;
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofTranslate(cameraPosition[0], cameraPosition[1]);
	Node* temp = linkedList.head;
	float xPos = 75;
	float yBase = 250;
	float offset = 0;
	while (temp) {
		float yOffset = sin(activeTime + offset) * amplitude;
		float yPos = yBase + yOffset;
		xPos += temp->data + 10;

		ofSetColor(255, 0, 0);
		ofDrawCircle(xPos, yPos, temp->data);

		ofSetColor(0);
		ofDrawBitmapString(ofToString(temp->data), xPos - 5, yPos + 5);

		if (temp->next) {
			ofSetColor(255, 0, 0);
			ofDrawLine(xPos, yPos, xPos + temp->data + temp->next->data + 10, yBase + sin(activeTime + offset + 0.5) * amplitude);
		}

		xPos += temp->data;
		temp = temp->next;
		offset += 0.5;
	}
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	bool sorted = false;
	switch (key) {
	case 'q':
		linkedList.insertAtHead(ofRandom(0, 100));
		break;
	case 'w':
		linkedList.insertAtTail(ofRandom(0, 100));
		break;
	case 'a':
		linkedList.deleteFromHead();
		break;
	case 's':
		linkedList.deleteFromTail();
		break;
	case 'e':
		if (!linkedList.head || !linkedList.head->next) {
			break;
		}
		do {
			sorted = true;
			Node* temp = linkedList.head;
			while (temp->next) {
				if (temp->data > temp->next->data) {
					sorted = false;
					std::swap(temp->data, temp->next->data);
				}
				temp = temp->next;
			}
		} while (!sorted);
		break;
	case 'z':
		amplitude += 10;
		break;
	case'x':
		amplitude -= 10;
		break;

	case OF_KEY_LEFT:
		cameraPosition[0] += 10;
		break;
	case OF_KEY_RIGHT:
		cameraPosition[0] -= 10;
		break;
	case OF_KEY_UP:
		cameraPosition[1] += 10;
		break;
	case OF_KEY_DOWN:
		cameraPosition[1] -= 10;
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
