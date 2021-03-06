#pragma once
#include "ofMain.h"
#include "box.h"
#include "ray.h"
#include "TreeNode.h"

class Octree {
public:
	
	void create(const ofMesh & mesh, int numLevels);
	void subdivide(const ofMesh & mesh, TreeNode & node, int numLevels, int level);
	bool intersect(const Ray &, const TreeNode & node, TreeNode & nodeRtn);
	void draw(TreeNode & node, int numLevels, int level);
	void draw(int numLevels, int level) {
		draw(root, numLevels, level);
	}
	void drawLeafNodes(TreeNode & node);
	static void drawBox(const Box &box);
	static Box meshBounds(const ofMesh &);
	int getMeshPointsInBox(const ofMesh &mesh, const vector<int> & points, Box & box, vector<int> & pointsRtn);
	void subDivideBox8(const Box &b, vector<Box> & boxList);
    bool checkSurfaceCollision(Vector3 & bboxPoint, TreeNode & node, vector<Vector3> & contactPoints);
    
    void averagePointsInLeafs() {
        cout << "Total Points in All Leafs " << totalPointsInLeaf << endl;
         cout << "Total Number of Leafs: " << numOfLeafs << endl;
        cout << "Average points in leaf is: " << (totalPointsInLeaf / numOfLeafs) << endl;
        
    }

	ofMesh mesh;
	TreeNode root;
    float totalPointsInLeaf;
    float numOfLeafs;
};
