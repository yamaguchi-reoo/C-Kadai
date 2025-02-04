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

	//既存のブロックデータをクリア
	blocks.clear();
	std::string line;

	//1行ずつデータを読み込む
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		StageData block;
		std::string item;


		//カンマ区切りでデータを取得し、各フィールドに格納
		std::getline(ss, item, ','); block.x = std::stoi(item);
		std::getline(ss, item, ','); block.y = std::stoi(item);
		std::getline(ss, item, ','); block.type = static_cast<eObjectType>(std::stoi(item));

		//ブロックリストに追加
		blocks.push_back(block);
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
