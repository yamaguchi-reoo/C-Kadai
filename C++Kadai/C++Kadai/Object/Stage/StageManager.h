#pragma once
#include <vector>
#include <string>
#include "../GameObject.h"

struct StageData{
	int x, y;
	eObjectType type;
};

class StageManager{
private:
	std::vector<StageData> blocks;

public:
	//ステージデータをCSVファイルに保存する
	void SaveCSV(const std::string& file_name);

	//CSVファイルからステージデータを読み込む
	void LoadCSV(const std::string& file_name);

	//新しいブロックをリストに追加する
	void AddBlock(int x, int y, eObjectType type);

	void AddObjectBlock(int x, int y, eObjectType type);

	//すべてのブロックデータを削除する
	void ClearBlock();

	const std::vector<StageData>& GetBlock()const { return blocks; }

};

