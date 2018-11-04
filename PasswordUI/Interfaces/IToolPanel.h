#pragma once

namespace PasswordUI {

enum class Tool;

class IToolPanel
{
public:
	virtual ~IToolPanel() = default;
	virtual void ActivateTool(Tool tool) = 0;
	virtual Tool GetActiveTool() const = 0;
};

}
