#include "ViewPreviewAccountInfo.h"

#include "ui_ViewPreviewAccountInfo.h"

using namespace PasswordUI;

ViewPreviewAccountInfo::ViewPreviewAccountInfo(QWidget* parent)
	: QFrame(parent)
	, m_ui(new Ui::ViewPreviewAccountInfo())
{
	m_ui->setupUi(this);
}

ViewPreviewAccountInfo::~ViewPreviewAccountInfo() = default;
