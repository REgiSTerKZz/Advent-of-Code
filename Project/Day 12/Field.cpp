#include "Field.h"


Field::Field()
{
	mField = std::vector<std::vector<Cell*>>();
}

void Field::GenerateNeighbours()
{
	// First we set the boundaries
	FIELD_HEIGHT = mField.size();
	FIELD_WIDTH = mField[0].size();

	// Now we iterate all the cells and check if there are available neighbours to move to;

	// Left -> Right & Top -> Bottom		--> mField[i][j]
	for (int i = 0; i < FIELD_HEIGHT; i++) {
		for (int j = 0; j < FIELD_WIDTH; j++) {
			// Check up
			if (i-1 >= 0) {
				mField[i][j]->AddNeighbour('U', mField[i - 1][j]);
			}
			// Check Down
			if (i+1 < FIELD_HEIGHT) {
				mField[i][j]->AddNeighbour('D', mField[i + 1][j]);
			}
			// Check Left
			if (j - 1 >= 0) {
				mField[i][j]->AddNeighbour('L', mField[i][j - 1]);
			}
			// Check Left
			if (j + 1 < FIELD_WIDTH) {
				mField[i][j]->AddNeighbour('R', mField[i][j + 1]);
			}
		}
	}
}

int Field::BFS()
{
	int totalSteps = 0;
	Cell* _cell = startCell;
	// Create queue
	std::list<Cell*> queue;

	// Mark the current Cell as visited
	_cell->visited = true;
	queue.push_back(_cell);

	while (!queue.empty()) {
		// Deque a Cell from the Queue
		_cell = queue.front();
		totalSteps++;
		queue.pop_front();
		// Get all neighbours
		for (int i = 0; i < 4; ++i)			// TODO: Change the Map Neighbours so we don't need to iterate 4 timeas each time
		{
			// Get neighbour
			if (_cell->mNeighbours.find(mDirections[i]) != _cell->mNeighbours.end())
			{
				//Found
				Cell* n = _cell->mNeighbours[mDirections[i]];

				// Check if neighbour is the desired cell
				if (n == this->goalCell)
				{
					n->cameFrom = _cell;
					return GetPathLength();
				}

				// Check if the neighbour has been visited
				if (!n->visited)
				{
					/* code */
					n->visited = true;
					n->cameFrom = _cell;
					queue.push_back(n);
				}
			}
		}
	}
	return totalSteps;
}

int Field::GetPathLength()
{
	int l = 0;
	Cell* c = goalCell;
	while (c != startCell)
	{
		mPath.push_back(c);
		c = c->cameFrom;
		if (c->height == 0)
		{ return l; }
		l++; 
	}
	return l;
}



bool Field::isBorder(int _pos, char c)
{
	return (c == 'X') ? (_pos == 0) || (_pos == FIELD_WIDTH) : (_pos == 0) || (_pos == FIELD_HEIGHT);
}
