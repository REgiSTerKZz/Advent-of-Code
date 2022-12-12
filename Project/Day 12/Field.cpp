#include "Field.h"


Field::Field()
{
	mField = std::vector<std::vector<Cell>>();
}

std::map<char, Cell> Field::GetNeighbours(Cell _c)
{
	return std::map<char, Cell>();
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
				mField[i][j].AddNeighbour('U', mField[i - 1][j]);
			}
			// Check Down
			if (i+1 < FIELD_HEIGHT) {
				mField[i][j].AddNeighbour('D', mField[i + 1][j]);
			}
			// Check Left
			if (j - 1 >= 0) {
				mField[i][j].AddNeighbour('L', mField[i][j - 1]);
			}
			// Check Left
			if (j + 1 < FIELD_WIDTH) {
				mField[i][j].AddNeighbour('R', mField[i][j + 1]);
			}
		}
	}
}



bool Field::isBorder(int _pos, char c)
{
	return (c == 'X') ? (_pos == 0) || (_pos == FIELD_WIDTH) : (_pos == 0) || (_pos == FIELD_HEIGHT);
}
