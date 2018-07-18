#pragma once

#include <memory>

#include <QDialog>
#include <QScopedPointer>

namespace Ui {
class PasswordGeneratorDialog;
}

namespace PasswordGenerator {
class IPasswordGenerator;
}

namespace PasswordUI {

class PasswordGeneratorDialog : public QDialog
{
	Q_OBJECT

public:
	enum class Mode
	{
		Independent = 0,
		Embeddable,
	};

public:
	explicit PasswordGeneratorDialog(Mode mode = Mode::Independent, size_t minLenght = 0, QWidget* parent = nullptr);
	~PasswordGeneratorDialog();

	const QString& GetPassowrd() const noexcept;

private:
	void Setup();
	void OnGenerate();

private:
	QScopedPointer<Ui::PasswordGeneratorDialog> m_ui;
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
