#include <cassert>
#include <vector>

#include "PasswordGenerator/Interfaces/IPasswordGenerator.h"
#include "PasswordGenerator/SimpleGenerator/SimpleGenerator.h"
#include "PasswordGenerator/Enums/ComponentsOfPassword.h"

#include "PasswordGeneratorDialog.h"
#include "ui_PasswordGeneratorDialog.h"

using namespace PasswordUI;
using namespace PasswordGenerator;

struct PasswordGeneratorDialog::Impl
{
	Impl(PasswordGeneratorDialog::Mode Mode)
		: mode(Mode)
		, generator(std::make_unique<SimpleGenerator>())
	{
	}

	std::vector<ComponentsOfPassword> GetComponents() const
	{
		std::vector<ComponentsOfPassword> components;

		for (const auto& [type, box] : parmetersCheckBoxs)
			if (box->isChecked())
				components.push_back(type);

		return components;
	}

	int GetCountChecked() const
	{
		return static_cast<int>(std::count_if(parmetersCheckBoxs.begin(), parmetersCheckBoxs.end(), [](const auto& item) { return item.second->isChecked(); }));
	}

	Mode mode;
	QString password;
	std::unique_ptr<PasswordGenerator::IPasswordGenerator> generator;
	std::vector<std::pair<ComponentsOfPassword, QCheckBox*>> parmetersCheckBoxs;
};

PasswordGeneratorDialog::PasswordGeneratorDialog(Mode mode, QWidget* parent)
	: QDialog(parent)
	, m_ui(new Ui::PasswordGeneratorDialog())
	, m_impl(std::make_unique<Impl>(mode))
{
	m_ui->setupUi(this);

	Setup();
}

PasswordGeneratorDialog::~PasswordGeneratorDialog() = default;

const QString&PasswordGeneratorDialog::GetPassowrd() const noexcept
{
	assert(m_impl->mode == Mode::Embeddable);
	return m_impl->password;
}

void PasswordGeneratorDialog::Setup()
{
	m_impl->parmetersCheckBoxs =
	{
		{ ComponentsOfPassword::Numerals,		m_ui->numeralsCheckBox },
		{ ComponentsOfPassword::UpperCase,		m_ui->upperCheckBox },
		{ ComponentsOfPassword::LowerCase,		m_ui->lowCheckBox },
		{ ComponentsOfPassword::SpecialSymbols,	m_ui->specialSymbolsCheckBox },
	};

	setWindowFlags (windowFlags() & ~Qt::WindowContextHelpButtonHint);

	m_ui->passwordBrowser->setVisible(m_impl->mode == Mode::Independent);
	m_ui->countFrame->setVisible(m_impl->mode == Mode::Independent);

	connect(m_ui->generateButton, &QAbstractButton::clicked, this, &PasswordGeneratorDialog::OnGenerate);

	for (const auto& item : m_impl->parmetersCheckBoxs)
		connect(item.second, &QCheckBox::clicked, [this](bool)
		{
			const auto count = m_impl->GetCountChecked();
			m_ui->generateButton->setEnabled(count > 0);
			m_ui->lengthSpinBox->setValue(m_ui->lengthSpinBox->value() > count ? m_ui->lengthSpinBox->value() : count);
			m_ui->lengthSpinBox->setMinimum(count);
		});
}

void PasswordGeneratorDialog::OnGenerate()
{
	const auto passwords = m_impl->generator->Generate(m_impl->GetComponents(), static_cast<size_t>(m_ui->lengthSpinBox->value()), static_cast<size_t>(m_ui->countSpinBox->value()));

	if (m_impl->mode == Mode::Independent)
	{
		m_ui->passwordBrowser->clear();

		for (const auto& row : passwords)
			m_ui->passwordBrowser->append(QString::fromStdString(row));
	}
	else
	{
		m_impl->password = QString::fromStdString(passwords[0]);
		emit accept();
	}
}
