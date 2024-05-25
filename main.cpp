#include <wx/wx.h>
#include <iostream>
#include <iomanip>
#include <limits> 


using namespace std;

class CalculatorFrame : public wxFrame
{
public:
    CalculatorFrame(const wxString& title);

private:
    void OnCalculate(wxCommandEvent& event);

    wxTextCtrl* num1Ctrl;
    wxTextCtrl* num2Ctrl;
    wxTextCtrl* oprCtrl;
    wxStaticText* resultText;
};

class CalculatorApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(CalculatorApp);

bool CalculatorApp::OnInit()
{
    CalculatorFrame* frame = new CalculatorFrame("Calculator");
    frame->Show(true);
    return true;
}

CalculatorFrame::CalculatorFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 300))
{
    wxPanel* panel = new wxPanel(this, -1);

    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer* hbox1 = new wxBoxSizer(wxHORIZONTAL);
    num1Ctrl = new wxTextCtrl(panel, wxID_ANY);
    hbox1->Add(num1Ctrl, 1);
    vbox->Add(hbox1, 0, wxEXPAND | wxALL, 10);

    wxBoxSizer* hbox2 = new wxBoxSizer(wxHORIZONTAL);
    oprCtrl = new wxTextCtrl(panel, wxID_ANY);
    hbox2->Add(oprCtrl, 1);
    vbox->Add(hbox2, 0, wxEXPAND | wxALL, 10);

    wxBoxSizer* hbox3 = new wxBoxSizer(wxHORIZONTAL);
    num2Ctrl = new wxTextCtrl(panel, wxID_ANY);
    hbox3->Add(num2Ctrl, 1);
    vbox->Add(hbox3, 0, wxEXPAND | wxALL, 10);

    wxBoxSizer* hbox4 = new wxBoxSizer(wxHORIZONTAL);
    wxButton* calculateButton = new wxButton(panel, wxID_ANY, wxT("Calculate"));
    hbox4->Add(calculateButton, 1);
    vbox->Add(hbox4, 0, wxALIGN_CENTER | wxALL, 10);

    wxBoxSizer* hbox5 = new wxBoxSizer(wxHORIZONTAL);
    resultText = new wxStaticText(panel, wxID_ANY, wxT("Result: "));
    hbox5->Add(resultText, 1);
    vbox->Add(hbox5, 0, wxALIGN_CENTER | wxALL, 10);

    panel->SetSizer(vbox);

    Connect(calculateButton->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CalculatorFrame::OnCalculate));
}

void CalculatorFrame::OnCalculate(wxCommandEvent& event)
{
    double num1, num2, result;
    wxString opr;

    num1Ctrl->GetValue().ToDouble(&num1);
    num2Ctrl->GetValue().ToDouble(&num2);
    opr = oprCtrl->GetValue();

    if (opr == "+")
        result = num1 + num2;
    else if (opr == "-")
        result = num1 - num2;
    else if (opr == "*")
        result = num1 * num2;
    else if (opr == "/")
    {
        if (num2 != 0)
            result = num1 / num2;
        else
        {
            wxMessageBox("Cannot divide by zero", "Error", wxOK | wxICON_ERROR);
            return;
        }
    }
    else if (opr == "%")
        result = static_cast<int>(num1) % static_cast<int>(num2);
    else
    {
        wxMessageBox("Invalid operator", "Error", wxOK | wxICON_ERROR);
        return;
    }

    resultText->SetLabel(wxString::Format("Result: %f", result));
}
