#ifndef DCRAWQTOPTIONS_H
#define DCRAWQTOPTIONS_H

#include <QtWidgets/QWidget>
#include <QHash>
#include <QtWidgets/QFileDialog>
#include "dcrawqt_global.h"

namespace Ui {
    class DcRawQTOptions;
}

class DCRAWQTSHARED_EXPORT DcRawQTOptions : public QWidget {
    Q_OBJECT
public:
    DcRawQTOptions(QWidget *parent = 0);
    ~DcRawQTOptions();
    QStringList DcRawQTArgs();
    QString commandline();
    void setcommandline(QString _commandline);

 signals:
    void commandlinechanged(QStringList args);

protected:
    void changeEvent(QEvent *e);

private: //Methods
    void setCustomWhiteBalance();
    void setChromaticAberation();
    void setGamma();
    void setSaturationLevel();
    void setAverageGrayBox();
    void setFlipImage();
    void setColorspace();
    void setMedianFilter();
    void setBrightness();
    void setDarknessLevel();
    void setFixDeadPixels();
    void setDarkFrameFilename();
    void setQuality();
    void setHighlightMode();
	void setDenoise();
	void updateCommandline();
    void parsecommandargs(QStringList _args);

private: //Fields
    Ui::DcRawQTOptions *m_ui;
    QHash<QString,QString> arguments;

private slots:
    void on_leGammaTS_textChanged(QString );
    void on_leGammaG_textChanged(QString );
    void on_sbHighlightMode_valueChanged(QString );
    void on_sbQuality_valueChanged(QString );
    void on_leDarkFrameFile_textChanged(QString );
    void on_leDeadPixelFile_textChanged(QString );
    void on_sbBrightness_valueChanged(QString );
    void on_dsbdenoise_valueChanged(QString );
    void on_sbMedianFilter_valueChanged(QString );
    void on_cbColorspace_currentIndexChanged(QString );
    void on_sbFlipImage_valueChanged(QString );
    void on_dsbDarknessLevel_valueChanged(QString );
    void on_customG2_textChanged(QString );
    void on_customB_textChanged(QString );
    void on_customG1_textChanged(QString );
    void on_customR_textChanged(QString );
    void on_grayBoxH_textChanged(QString );
    void on_grayBoxW_textChanged(QString );
    void on_grayBoxY_textChanged(QString );
    void on_grayBoxX_textChanged(QString );
    void on_leChromaticAberationB_textChanged(QString );
    void on_leChromaticAberationR_textChanged(QString );
    void on_cbColorspace_activated(int index);
    void on_dsbSaturationLevel_valueChanged(QString );
    void on_sbHighlightMode_editingFinished();
    void on_gbHighlightMode_toggled(bool );
    void on_sbQuality_editingFinished();
    void on_gbQuality_toggled(bool );
    void on_pushButton_2_clicked();
    void on_leDarkFrameFile_editingFinished();
    void on_gbDarkFrameFile_toggled(bool );
    void on_pushButton_clicked();
    void on_leDeadPixelFile_editingFinished();
    void on_gbFixDeadPixels_toggled(bool );
    void on_cbWriteTiff_toggled(bool checked);
    void on_cbLinear16bit_toggled(bool checked);
    void on_cbWrite16Bit_toggled(bool checked);
    void on_cbDontStretch_toggled(bool checked);
    void on_cbInterpRGGB_toggled(bool checked);
    void on_cbHalfSize_toggled(bool checked);
    void on_cbEmbeddedColorMatrix_toggled(bool checked);
    void on_rbNoColorNoInterp_toggled(bool checked);
    void on_rbNoScaling_toggled(bool checked);
    void on_rbNoAutoBrighten_toggled(bool checked);
    void on_rbBrightness_toggled(bool checked);
    void on_gbMedianFilter_toggled(bool );
    void on_gbColorspace_toggled(bool );
    void on_sbFlipImage_editingFinished();
    void on_gbFlipImage_toggled(bool );
    void on_gbDarknessLevel_toggled(bool );
    void on_grayBoxH_editingFinished();
    void on_grayBoxW_editingFinished();
    void on_grayBoxY_editingFinished();
    void on_grayBoxX_editingFinished();
    void on_dsbSaturationLevel_editingFinished();
    void on_gbSaturationLevel_toggled(bool );
    void on_leGammaTS_editingFinished();
    void on_leGammaG_editingFinished();
    void on_gbUseGamma_toggled(bool );
    void on_leChromaticAberationB_editingFinished();
    void on_leChromaticAberationR_editingFinished();
    void on_gbChromaticAberation_toggled(bool );
    void on_rbCameraWhiteBalance_toggled(bool checked);
    void on_rbAverageGrayBox_toggled(bool checked);
    void on_customG2_editingFinished();
    void on_customB_editingFinished();
    void on_customG1_editingFinished();
    void on_rbCustomWhiteBalance_toggled(bool checked);
    void on_customR_editingFinished();
	void on_gbDenoise_toggled(bool checked);
	void on_dsbdenoise_editingFinished();
};

#endif // DCRAWQTOPTIONS_H
