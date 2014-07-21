#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

#include "scenepreset.h"

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SettingsDialog(ScenePreset* priv, QWidget *parent = 0);
    ~SettingsDialog();
    


public slots:
    void presetChanged();

private:
    Ui::SettingsDialog *ui;
    ScenePreset *priv;

private slots:

    void settingChanged();
};

#endif // SETTINGSDIALOG_H
