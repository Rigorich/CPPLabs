//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *EditName;
	TRadioGroup *RadioGroupSex;
	TEdit *EditAge;
	TEdit *EditDiagnosis;
	TEdit *EditWard;
	TButton *ButtonSaveChanges;
	TButton *ButtonDelete;
	TComboBox *ComboBoxSearch;
	TEdit *EditSearch;
	TListBox *ListBox;
	TOpenDialog *OpenDialog;
	TButton *ButtonOpenDialog;
	TSaveDialog *SaveDialog;
	TButton *ButtonSaveDialog;
	TRadioGroup *RadioButtonList;
	TButton *ButtonFlushList;
	TCheckBox *CheckBoxAddPatient;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	void __fastcall ButtonSaveDialogClick(TObject *Sender);
	void __fastcall ButtonOpenDialogClick(TObject *Sender);
	void __fastcall ButtonSaveChangesClick(TObject *Sender);
	void __fastcall ButtonFlushListClick(TObject *Sender);
	void __fastcall CheckBoxAddPatientClick(TObject *Sender);
	void __fastcall RadioButtonListClick(TObject *Sender);
	void __fastcall ButtonDeleteClick(TObject *Sender);
	void __fastcall ButtonSearchClick(TObject *Sender);
	void __fastcall ListBoxClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
