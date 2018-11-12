#pragma once

namespace PasswordUI {

enum class Tool;

class IToolsPanel
{
public:
	virtual ~IToolsPanel() = default;
	virtual void ActivateTool(Tool tool) = 0;
	virtual Tool GetActiveTool() const = 0;
};

}
