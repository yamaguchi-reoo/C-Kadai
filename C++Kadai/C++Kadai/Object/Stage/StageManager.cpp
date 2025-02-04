#include "StageManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <DxLib.h>


void StageManager::SaveCSV(const std::string& file_name)
{
	std::ofstream file(file_name);
	if (!file) {
		std::cerr << "ファイルを開けませんでした: " << file_name << std::endl;
		return;
	}

	// すべてのブロックデータをCSV形式で保存
	for (const auto& block : blocks)
	{
		file << block.x << "," << block.y << "," << block.type << "\n";
	}

	file.close();
	std::cout << "ステージデータ保存\n";
}

void StageManager::LoadCSV(const std::string& file_name)
{
	std::ifstream file(file_name);

	if (!file){
		std::cerr << "ファイルを開けませんでした: " << file_name << std::endl;
		return;
	}

	// ステージデータの幅と高さを読み込む
	file >> stage_width_num;
	file >> stage_height_num;

	// ステージの幅と高さを設定
	stage_width = stage_width_num * BOX_SIZE;
	stage_height = stage_height_num * BOX_SIZE;

	// ステージデータの配列を読み込む
	for (int i = 0; i < stage_height_num; i++) {
		for (int j = 0; j < stage_width_num; j++) {
			file >> stage_data[i][j];  // 各ブロックの種類を読み込む
		}
	}

	//既存のブロックデータをクリア
	blocks.clear();
	std::string line;

	// CSVのファイルを1行ずつ読み込んで、各ブロックの座標と種類をStageDataに設定
	for (int i = 0; i < stage_height_num; i++) {
		for (int j = 0; j < stage_width_num; j++) {
			StageData block;
			block.x = j * BOX_SIZE;  // X座標を設定（ブロック幅で乗算）
			block.y = i * BOX_SIZE; // Y座標を設定（ブロック高さで乗算）
			block.type = static_cast<eObjectType>(stage_data[i][j]); // ステージデータの値をタイプに変換

			// blocksに追加
			blocks.push_back(block);
		}
	}

	file.close();
	std::cout << "ステージデータ読み込みました\n";
}

void StageManager::AddBlock(int x, int y, eObjectType type)
{
	blocks.push_back({ x, y, type });
}

void StageManager::AddObjectBlock(int x, int y, eObjectType type)
{
}

void StageManager::ClearBlock()
{
	blocks.clear();
}
