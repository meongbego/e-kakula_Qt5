#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(ScenePreset *scene_preset, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog),
    priv(scene_preset)
{
    ui->setupUi(this);
    connect(ui->sldScale, SIGNAL(valueChanged(int)), this, SLOT(settingChanged()));
    connect(ui->chkMagnitude, SIGNAL(stateChanged(int)), this, SLOT(settingChanged()));
    connect(ui->chkMovingCamera, SIGNAL(stateChanged(int)), this, SLOT(settingChanged()));
    connect(ui->sldFloorX, SIGNAL(valueChanged(int)),this,SLOT(settingChanged()));
    connect(ui->sldStepZ,SIGNAL(valueChanged(int)), this, SLOT(settingChanged()));
    connect(ui->chkFlashlight,SIGNAL(stateChanged(int)),this, SLOT(settingChanged()));
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}


void SettingsDialog::presetChanged()
{
    ui->sldScale->setValue(priv->scale);
    ui->chkMagnitude->setChecked(priv->use_magnitude);
    ui->chkMovingCamera->setChecked(priv->cammove);
    ui->sldFloorX->setValue(priv->rot_x);
    ui->sldStepZ->setValue(priv->step_z*10.0f);
    ui->chkFlashlight->setChecked(priv->cinvert);
}

void SettingsDialog::settingChanged()
{
    priv->use_magnitude = ui->chkMagnitude->isChecked();
    priv->scale = ui->sldScale->value();
    priv->cammove = ui->chkMovingCamera->isChecked();
    priv->rot_x = ui->sldFloorX->value();
    priv->step_z = ui->sldStepZ->value()/10.0f;
    priv->cinvert = ui->chkFlashlight->isChecked();
}
