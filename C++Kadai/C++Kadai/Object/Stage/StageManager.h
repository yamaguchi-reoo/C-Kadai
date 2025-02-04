#pragma once
#include <vector>
#include <string>
#include "../GameObject.h"

#define BOX_SIZE 32
#define STAGE_MAX_WIDTH 500
#define STAGE_MAX_HEIGHT 500

struct StageData{
	int x, y;
	eObjectType type;
};

class StageManager{
private:
	std::vector<StageData> blocks;
	int stage_width_num;    //ステージの横のブロック数
	int stage_height_num;   //ステージの縦のブロック数
	int stage_width;        //ステージの横の大きさ
	int stage_height;       //ステージの縦の大きさ

	int stage_data[STAGE_MAX_WIDTH][STAGE_MAX_HEIGHT];

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

