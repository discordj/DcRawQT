#include "dcrawqtoptions.h"
#include "ui_dcrawqtoptions.h"

DcRawQTOptions::DcRawQTOptions(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::DcRawQTOptions)
{
    m_ui->setupUi(this);
}

DcRawQTOptions::~DcRawQTOptions()
{
    delete m_ui;
}

void DcRawQTOptions::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void DcRawQTOptions::on_customR_editingFinished()
{
    setCustomWhiteBalance();
}

void DcRawQTOptions::on_rbCustomWhiteBalance_toggled(bool checked)
{
        setCustomWhiteBalance();
}
void DcRawQTOptions::setCustomWhiteBalance()
{
    if(arguments.contains(QString("-r")))
        arguments.remove(QString("-r"));
    if(m_ui->rbCustomWhiteBalance->isChecked())
    {

        arguments.insert(QString("-r"),
              QString("-r %1 %2 %3 %4").arg(m_ui->customR->text()).arg(m_ui->customG1->text()).arg(m_ui->customB->text()).arg(m_ui->customG2->text()));

    }
    updateCommandline();
 }
void DcRawQTOptions::on_customG1_editingFinished()
{
    setCustomWhiteBalance();
}

void DcRawQTOptions::on_customB_editingFinished()
{
    setCustomWhiteBalance();
}

void DcRawQTOptions::on_customG2_editingFinished()
{
    setCustomWhiteBalance();
}

void DcRawQTOptions::setAverageGrayBox()
{
    if(arguments.contains(QString("-A")))
        arguments.remove(QString("-A"));
    if(m_ui->rbAverageGrayBox->isChecked())
    {

        arguments.insert(QString("-A"),
              QString("-A %1 %2 %3 %4").arg(m_ui->grayBoxX->text()).arg(m_ui->grayBoxY->text()).arg(m_ui->grayBoxW->text()).arg(m_ui->grayBoxH->text()));

    }
    updateCommandline();
}

void DcRawQTOptions::on_rbAverageGrayBox_toggled(bool checked)
{
        setAverageGrayBox();
}

void DcRawQTOptions::on_grayBoxX_editingFinished()
{
    setAverageGrayBox();
}

void DcRawQTOptions::on_grayBoxY_editingFinished()
{
    setAverageGrayBox();
}

void DcRawQTOptions::on_grayBoxW_editingFinished()
{
    setAverageGrayBox();
}

void DcRawQTOptions::on_grayBoxH_editingFinished()
{
    setAverageGrayBox();
}

void DcRawQTOptions::on_rbCameraWhiteBalance_toggled(bool checked)
{
    if(checked)
    {
        if(arguments.contains(QString("-w")))
            arguments.remove(QString("-w"));

        arguments.insert(QString("-w"), QString("-w"));

        updateCommandline();
    }
    else
    {
        if(arguments.contains(QString("-w")))
            arguments.remove(QString("-w"));

        updateCommandline();
    }

}

void DcRawQTOptions::on_gbChromaticAberation_toggled(bool checked)
{
        setChromaticAberation();

}

void DcRawQTOptions::setChromaticAberation()
{
    if(arguments.contains(QString("-C")))
        arguments.remove(QString("-C"));
    if( m_ui->gbChromaticAberation->isChecked())
    {

        arguments.insert(QString("-C"), QString("-C %1 %2").arg(m_ui->leChromaticAberationR->text()).arg(m_ui->leChromaticAberationB->text()));

    }
    updateCommandline();
}

void DcRawQTOptions::on_leChromaticAberationR_editingFinished()
{
    setChromaticAberation();
}

void DcRawQTOptions::on_leChromaticAberationB_editingFinished()
{
    setChromaticAberation();
}

void DcRawQTOptions::setGamma()
{
    if(arguments.contains(QString("-g")))
        arguments.remove(QString("-g"));
    if(m_ui->gbUseGamma->isChecked())
    {

        arguments.insert(QString("-g"), QString("-g %1 %2").arg(m_ui->leGammaG->text()).arg(m_ui->leGammaTS->text()));

    }
    updateCommandline();
}

void DcRawQTOptions::on_gbUseGamma_toggled(bool checked )
{
        setGamma();
}

void DcRawQTOptions::on_leGammaG_editingFinished()
{
    setGamma();
}

void DcRawQTOptions::on_leGammaTS_editingFinished()
{
    setGamma();
}

void DcRawQTOptions::setSaturationLevel()
{
    if(arguments.contains(QString("-S")))
        arguments.remove(QString("-S"));
    if(m_ui->gbSaturationLevel->isChecked())
    {

        arguments.insert(QString("-S"), QString("-S %1").arg(m_ui->dsbSaturationLevel->value(),0,'f',2));

    }
    updateCommandline();
}

void DcRawQTOptions::on_gbSaturationLevel_toggled(bool checked)
{
        setSaturationLevel();
}

void DcRawQTOptions::on_dsbSaturationLevel_editingFinished()
{
    setSaturationLevel();
}


void DcRawQTOptions::setDarknessLevel()
{
    if(arguments.contains(QString("-k")))
        arguments.remove(QString("-k"));
    if(m_ui->gbDarknessLevel->isChecked())
    {

        arguments.insert(QString("-k"), QString("-k %1").arg(m_ui->dsbDarknessLevel->value(),0,'f',2));

    }
    updateCommandline();
}

void DcRawQTOptions::on_gbDarknessLevel_toggled(bool checked)
{
        setDarknessLevel();

}

void DcRawQTOptions::setFlipImage()
{
    if(arguments.contains(QString("-t")))
        arguments.remove(QString("-t"));
    if(m_ui->gbFlipImage->isChecked())
    {

        arguments.insert(QString("-t"), QString("-t %1").arg(m_ui->sbFlipImage->value()));

    }
    updateCommandline();
}

void DcRawQTOptions::on_gbFlipImage_toggled(bool checked)
{
        setFlipImage();

}

void DcRawQTOptions::on_sbFlipImage_editingFinished()
{
    setFlipImage();
}

void DcRawQTOptions::setColorspace()
{
    if(arguments.contains(QString("-o")))
        arguments.remove(QString("-o"));
    if(m_ui->gbColorspace->isChecked())
    {

        arguments.insert(QString("-o"), QString("-o %1").arg(m_ui->cbColorspace->currentIndex()));

    }
    updateCommandline();
}

void DcRawQTOptions::on_gbColorspace_toggled(bool checked )
{
        setColorspace();

}

void DcRawQTOptions::setMedianFilter()
{
    if(arguments.contains(QString("-m")))
        arguments.remove(QString("-m"));
    if(m_ui->gbMedianFilter->isChecked())
    {

        arguments.insert(QString("-m"), QString("-m %1").arg(m_ui->sbMedianFilter->value()));

    }
    updateCommandline();
}

void DcRawQTOptions::on_gbMedianFilter_toggled(bool checked)
{
        setMedianFilter();
}

void DcRawQTOptions::setDenoise()
{
    if(arguments.contains(QString("-n")))
        arguments.remove(QString("-n"));
    if(m_ui->gbDenoise->isChecked())
    {
        arguments.insert(QString("-n"), QString("-n %1").arg(m_ui->dsbdenoise->value()));
    }

    updateCommandline();
}

void DcRawQTOptions::on_gbDenoise_toggled(bool checked)
{
	setDenoise();
}

void DcRawQTOptions::on_dsbdenoise_editingFinished()
{
	setDenoise();
}

void DcRawQTOptions::on_dsbdenoise_valueChanged(QString )
{
    setDenoise();
}


void DcRawQTOptions::setBrightness()
{
    if(arguments.contains(QString("-b")))
        arguments.remove(QString("-b"));
    if(m_ui->rbBrightness->isChecked())
    {

        arguments.insert(QString("-b"), QString("-b %1").arg(m_ui->sbBrightness->value(),0,'f',2));

    }
    updateCommandline();
}

void DcRawQTOptions::on_rbBrightness_toggled(bool checked)
{
        setBrightness();
}

void DcRawQTOptions::on_rbNoAutoBrighten_toggled(bool checked)
{
    if(checked)
    {
        if(arguments.contains(QString("-W")))
            return;

        arguments.insert(QString("-W"), QString("-W"));
    }
    else
    {
        if(arguments.contains(QString("-W")))
            arguments.remove(QString("-W"));
    }

    updateCommandline();

}

void DcRawQTOptions::on_rbNoScaling_toggled(bool checked)
{
    if(checked)
    {
        if(arguments.contains(QString("-D")))
            return;

        arguments.insert(QString("-D"), QString("-D"));

		if(arguments.contains(QString("-6")))
			m_ui->cbWriteTiff->setChecked(true);
    }
    else
    {
        if(arguments.contains(QString("-D")))
            arguments.remove(QString("-D"));
    }

    updateCommandline();

}

void DcRawQTOptions::on_rbNoColorNoInterp_toggled(bool checked)
{
    if(checked)
    {
        if(arguments.contains(QString("-d")))
            return;

        arguments.insert(QString("-d"), QString("-d"));

		if(arguments.contains(QString("-6")))
			m_ui->cbWriteTiff->setChecked(true);
    }
    else
    {
        if(arguments.contains(QString("-d")))
            arguments.remove(QString("-d"));
    }

    updateCommandline();
}



void DcRawQTOptions::on_cbEmbeddedColorMatrix_toggled(bool checked)
{
    if(checked)
    {
        if(arguments.contains(QString("+M")))
            return;

        arguments.insert(QString("+M"), QString("+M"));
    }
    else
    {
        if(arguments.contains(QString("+M")))
            arguments.remove(QString("+M"));
    }

    updateCommandline();
}

void DcRawQTOptions::on_cbHalfSize_toggled(bool checked)
{
    if(checked)
    {
        if(arguments.contains(QString("-h")))
            return;

        arguments.insert(QString("-h"), QString("-h"));
    }
    else
    {
        if(arguments.contains(QString("-h")))
            arguments.remove(QString("-h"));
    }

    updateCommandline();
}

void DcRawQTOptions::on_cbInterpRGGB_toggled(bool checked)
{
    if(checked)
    {
        if(arguments.contains(QString("-f")))
            return;

        arguments.insert(QString("-f"), QString("-f"));
    }
    else
    {
        if(arguments.contains(QString("-f")))
            arguments.remove(QString("-f"));
    }

    updateCommandline();
}

void DcRawQTOptions::on_cbDontStretch_toggled(bool checked)
{
    if(checked)
    {
        if(arguments.contains(QString("-j")))
            return;

        arguments.insert(QString("-j"), QString("-j"));
    }
    else
    {
        if(arguments.contains(QString("-j")))
            arguments.remove(QString("-j"));
    }

    updateCommandline();
}

void DcRawQTOptions::on_cbWrite16Bit_toggled(bool checked)
{
    if(checked)
    {
        if(arguments.contains(QString("-6")))
            return;

        arguments.insert(QString("-6"), QString("-6"));
		
		if(arguments.contains(QString("-d")) || arguments.contains(QString("-D")))
			m_ui->cbWriteTiff->setChecked(true);

    }
    else
    {
        if(arguments.contains(QString("-6")))
            arguments.remove(QString("-6"));
    }

    updateCommandline();
}

void DcRawQTOptions::on_cbLinear16bit_toggled(bool checked)
{
    if(checked)
    {
        if(arguments.contains(QString("-4")))
            return;

        arguments.insert(QString("-4"), QString("-4"));
    }
    else
    {
        if(arguments.contains(QString("-4")))
            arguments.remove(QString("-4"));
    }

    updateCommandline();
}

void DcRawQTOptions::on_cbWriteTiff_toggled(bool checked)
{
    if(checked)
    {
        if(arguments.contains(QString("-T")))
            return;

        arguments.insert(QString("-T"), QString("-T"));
    }
    else
    {
		if((arguments.contains(QString("-d")) || arguments.contains(QString("-D"))) && arguments.contains(QString("-6"))){
			m_ui->cbWriteTiff->setChecked(true);
			return;
		}
        if(arguments.contains(QString("-T")))
            arguments.remove(QString("-T"));
    }

    updateCommandline();
}

void DcRawQTOptions::setFixDeadPixels()
{
    if(arguments.contains(QString("-P")))
        arguments.remove(QString("-P"));
    if(m_ui->gbFixDeadPixels->isChecked())
    {

        arguments.insert(QString("-P"), QString("-P \"%1\"").arg(m_ui->leDeadPixelFile->text()));

    }
    updateCommandline();
}

void DcRawQTOptions::on_gbFixDeadPixels_toggled(bool checked)
{
        setFixDeadPixels();
}

void DcRawQTOptions::on_leDeadPixelFile_editingFinished()
{
    setFixDeadPixels();
}

void DcRawQTOptions::on_pushButton_clicked()
{
    QString deadPixelFile = QFileDialog::getOpenFileName(this,"Open Dead Pixel File");

    if(deadPixelFile == QString::Null()) return;

    m_ui->leDeadPixelFile->setText(deadPixelFile);

    setFixDeadPixels();
}

void DcRawQTOptions::setDarkFrameFilename()
{
    if(arguments.contains(QString("-K")))
        arguments.remove(QString("-K"));
    if(m_ui->gbDarkFrameFile->isChecked())
    {

        arguments.insert(QString("-K"), QString("-K %1").arg(m_ui->leDarkFrameFile->text()));

    }
    updateCommandline();
}

void DcRawQTOptions::on_gbDarkFrameFile_toggled(bool checked)
{
        setDarkFrameFilename();
}

void DcRawQTOptions::on_leDarkFrameFile_editingFinished()
{
    setDarkFrameFilename();
}

void DcRawQTOptions::on_pushButton_2_clicked()
{
    QString darkFrameFile = QFileDialog::getOpenFileName(this,"Open Dark Frame File");

    if(darkFrameFile == QString::Null()) return;

    m_ui->leDarkFrameFile->setText(darkFrameFile);

    setDarkFrameFilename();
}

void DcRawQTOptions::setQuality()
{
    if(arguments.contains(QString("-q")))
        arguments.remove(QString("-q"));
    if(m_ui->gbQuality->isChecked())
    {

        arguments.insert(QString("-q"), QString("-q %1").arg(m_ui->sbQuality->value()));

    }
    updateCommandline();
}

void DcRawQTOptions::on_gbQuality_toggled(bool checked)
{
        setQuality();
}

void DcRawQTOptions::on_sbQuality_editingFinished()
{
    setQuality();
}

void DcRawQTOptions::setHighlightMode()
{
    if(arguments.contains(QString("-H")))
        arguments.remove(QString("-H"));
    if(m_ui->gbHighlightMode->isChecked())
    {

        arguments.insert(QString("-H"), QString("-H %1").arg(m_ui->sbHighlightMode->value()));
    }
    updateCommandline();
}

void DcRawQTOptions::on_gbHighlightMode_toggled(bool checked)
{
        setHighlightMode();
}

void DcRawQTOptions::on_sbHighlightMode_editingFinished()
{
    setHighlightMode();
}

QString DcRawQTOptions::commandline()
{
    QString newcommandline = QString("DcRawQT ");

    QHashIterator<QString, QString> i(arguments);
    while (i.hasNext()) {
         i.next();
         newcommandline += QString(" ") + QString("%1").arg(i.value());
    }

    return newcommandline;
}

void DcRawQTOptions::updateCommandline()
{

    m_ui->lblCommandLine->setText(commandline());

    emit commandlinechanged(DcRawQTArgs());

}

void DcRawQTOptions::setcommandline(QString _commandline)
{
    parsecommandargs(_commandline.split(' ',QString::SkipEmptyParts));



}

void DcRawQTOptions::parsecommandargs(QStringList _args)
{

    QStringListIterator i(_args);

    m_ui->rbNoWhiteBalance->setChecked(true);
    m_ui->rbNoBirghtness->setChecked(true);
    m_ui->rbNoDocumentMode->setChecked(true);
    m_ui->gbSaturationLevel->setChecked(false);
    m_ui->gbDarknessLevel->setChecked(false);
    m_ui->gbChromaticAberation->setChecked(false);
    m_ui->gbUseGamma->setChecked(false);
    m_ui->gbFixDeadPixels->setChecked(false);
    m_ui->gbColorspace->setChecked(false);
    m_ui->gbDarkFrameFile->setChecked(false);
    m_ui->gbQuality->setChecked(false);
    m_ui->gbHighlightMode->setChecked(false);
    m_ui->cbEmbeddedColorMatrix->setChecked(false);
    m_ui->cbHalfSize->setChecked(false);
    m_ui->cbInterpRGGB->setChecked(false);
    m_ui->cbDontStretch->setChecked(false);
    m_ui->cbLinear16bit->setChecked(false);
    m_ui->cbWriteTiff->setChecked(false);
    m_ui->cbWriteTiff->setChecked(false);
    m_ui->gbMedianFilter->setChecked(false);
    m_ui->gbFlipImage->setChecked(false);
    m_ui->cbWrite16Bit->setChecked(false);
    m_ui->gbDenoise->setChecked(false);


    while(i.hasNext())
    {
        QString arg = i.next();


        if(arg.compare("-w") == 0){
            m_ui->rbCameraWhiteBalance->setChecked(true);
        }
        else if(arg.compare("-A") == 0){
            m_ui->rbAverageGrayBox->setChecked(true);
            m_ui->grayBoxX->setText(i.hasNext() ? i.next(): tr("0"));
            m_ui->grayBoxY->setText(i.hasNext() ? i.next(): tr("0"));
            m_ui->grayBoxW->setText(i.hasNext() ? i.next(): tr("0"));
            m_ui->grayBoxH->setText(i.hasNext() ? i.next(): tr("0"));
        }
        else if(arg.compare("-r") == 0)
        {
            m_ui->rbCustomWhiteBalance->setChecked(true);
            m_ui->customR->setText(i.hasNext() ? i.next(): tr("0"));
            m_ui->customG1->setText(i.hasNext() ? i.next(): tr("0"));
            m_ui->customB->setText(i.hasNext() ? i.next(): tr("0"));
            m_ui->customG2->setText(i.hasNext() ? i.next(): tr("0"));
        }
        else if(arg.compare("-S") == 0)
        {
            m_ui->gbSaturationLevel->setChecked(true);
            m_ui->dsbSaturationLevel->setValue(i.hasNext() ? ((QString)i.next()).toDouble() : 0.00);
        }
        else if(arg.compare("-k") == 0)
        {
            m_ui->gbDarknessLevel->setChecked(true);
            m_ui->dsbDarknessLevel->setValue(i.hasNext() ? ((QString)i.next()).toDouble() : 0.00);
        }
        else if(arg.compare("-C") == 0)
        {
            m_ui->gbChromaticAberation->setChecked(true);
            m_ui->leChromaticAberationR->setText(i.hasNext() ? i.next() : "0");
            m_ui->leChromaticAberationB->setText(i.hasNext() ? i.next(): "0");
        }
        else if(arg.compare("-g") == 0)
        {
            m_ui->gbUseGamma->setChecked(true);
            m_ui->leGammaG->setText(i.hasNext()? i.next() : "0");
            m_ui->leGammaTS->setText(i.hasNext()?i.next(): "0");
        }
        else if(arg.compare("-t") == 0)
        {
            m_ui->gbFlipImage->setChecked(true);
            m_ui->sbFlipImage->setValue(i.hasNext()? ((QString)i.next()).toInt() : 0);
        }
        else if(arg.compare("-o") == 0)
        {
            m_ui->gbColorspace->setChecked(true);
            m_ui->cbColorspace->setCurrentIndex(i.hasNext()? ((QString)i.next()).toInt() : 0);
        }
        else if(arg.compare("-m") == 0)
        {
            m_ui->gbMedianFilter->setChecked(true);
            m_ui->sbMedianFilter->setValue(i.hasNext()? ((QString)i.next()).toInt() : 0);
        }
        else if(arg.compare("-W") == 0)
        {
            m_ui->rbNoAutoBrighten->setChecked(true);
        }
        else if(arg.compare("-b") == 0)
        {
            m_ui->rbBrightness->setChecked(true);
            m_ui->sbBrightness->setValue(i.hasNext()? ((QString)i.next()).toDouble() : 0.00);
        }
        else if(arg.compare("-d") == 0)
        {
            m_ui->rbNoColorNoInterp->setChecked(true);
        }
        else if(arg.compare("-D") == 0)
        {
            m_ui->rbNoScaling->setChecked(true);
        }
        else if(arg.compare("+M") == 0)
        {
            m_ui->cbEmbeddedColorMatrix->setChecked(true);
        }
        else if(arg.compare("-h") == 0)
        {
            m_ui->cbHalfSize->setChecked(true);
        }
        else if(arg.compare("-f") == 0)
        {
            m_ui->cbInterpRGGB->setChecked(true);
        }
        else if(arg.compare("-j") == 0)
        {
            m_ui->cbDontStretch->setChecked(true);
        }
        else if(arg.compare("-6") == 0)
        {
            m_ui->cbWrite16Bit->setChecked(true);
        }
        else if(arg.compare("-4") == 0)
        {
            m_ui->cbLinear16bit->setChecked(true);
        }
        else if(arg.compare("-T") == 0)
        {
            m_ui->cbWriteTiff->setChecked(true);
        }
        else if(arg.compare("-P") == 0)
        {
            m_ui->gbFixDeadPixels->setChecked(true);
            m_ui->leDeadPixelFile->setText(i.hasNext()? ((QString)i.next()) : tr(""));
        }
        else if(arg.compare("-K") == 0)
        {
            m_ui->gbDarkFrameFile->setChecked(true);
            m_ui->leDarkFrameFile->setText(i.hasNext()? ((QString)i.next()) : tr(""));
        }
        else if(arg.compare("-q") == 0)
        {
            m_ui->gbQuality->setChecked(true);
            m_ui->sbQuality->setValue(i.hasNext()? ((QString)i.next()).toInt() : 0);
        }
        else if(arg.compare("-H") == 0)
        {
            m_ui->gbHighlightMode->setChecked(true);
            m_ui->sbHighlightMode->setValue(i.hasNext()? ((QString)i.next()).toInt() : 0);
        }
        else if(arg.compare("-n") == 0)
        {
                m_ui->gbDenoise->setChecked(true);
                m_ui->dsbdenoise->setValue(i.hasNext() ? ((QString)i.next()).toDouble() : 0.00);
        }

    }
}

QStringList DcRawQTOptions::DcRawQTArgs()
{
    QStringList newcommandline;

    newcommandline += QString("DcRawQT");
    //newcommandline += "-c";
//    if(arguments.size() <= 0) {
//        commandline += "-c";
//        return commandline;
//    }

    QHashIterator<QString, QString> i(arguments);
    while (i.hasNext()) {
         i.next();
         newcommandline += i.value().split(' ',QString::SkipEmptyParts);
    }

    return newcommandline;
}

void DcRawQTOptions::on_dsbSaturationLevel_valueChanged(QString )
{
        setSaturationLevel();
}

void DcRawQTOptions::on_cbColorspace_activated(int index)
{
    setColorspace();
}

void DcRawQTOptions::on_leChromaticAberationR_textChanged(QString )
{
    setChromaticAberation();
}

void DcRawQTOptions::on_leChromaticAberationB_textChanged(QString )
{
    setChromaticAberation();
}

void DcRawQTOptions::on_grayBoxX_textChanged(QString )
{
    setAverageGrayBox();
}

void DcRawQTOptions::on_grayBoxY_textChanged(QString )
{
    setAverageGrayBox();
}

void DcRawQTOptions::on_grayBoxW_textChanged(QString )
{
    setAverageGrayBox();
}

void DcRawQTOptions::on_grayBoxH_textChanged(QString )
{
    setAverageGrayBox();
}

void DcRawQTOptions::on_customR_textChanged(QString )
{
    setCustomWhiteBalance();
}

void DcRawQTOptions::on_customG1_textChanged(QString )
{
    setCustomWhiteBalance();
}

void DcRawQTOptions::on_customB_textChanged(QString )
{
    setCustomWhiteBalance();
}

void DcRawQTOptions::on_customG2_textChanged(QString )
{
    setCustomWhiteBalance();
}

void DcRawQTOptions::on_dsbDarknessLevel_valueChanged(QString )
{
    setDarknessLevel();
}

void DcRawQTOptions::on_sbFlipImage_valueChanged(QString )
{
    setFlipImage();
}

void DcRawQTOptions::on_cbColorspace_currentIndexChanged(QString )
{
    setColorspace();
}

void DcRawQTOptions::on_sbMedianFilter_valueChanged(QString )
{
    setMedianFilter();
}

void DcRawQTOptions::on_sbBrightness_valueChanged(QString )
{
    setBrightness();
}

void DcRawQTOptions::on_leDeadPixelFile_textChanged(QString )
{
    setFixDeadPixels();
}

void DcRawQTOptions::on_leDarkFrameFile_textChanged(QString )
{
    setDarkFrameFilename();
}

void DcRawQTOptions::on_sbQuality_valueChanged(QString )
{
    setQuality();
}

void DcRawQTOptions::on_sbHighlightMode_valueChanged(QString )
{
    setHighlightMode();
}

void DcRawQTOptions::on_leGammaG_textChanged(QString )
{
    setGamma();
}

void DcRawQTOptions::on_leGammaTS_textChanged(QString )
{
    setGamma();
}
