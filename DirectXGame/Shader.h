#pragma once

#include <string>
#include <d3d12.h>

class Shader {
public:
	void Load(const std::wstring& filePath, const std::string& shaderModel);

	ID3DBlob* GetBlob();

	Shader();

	~Shader();

	private:
	ID3DBlob* blob_ = nullptr;
};
