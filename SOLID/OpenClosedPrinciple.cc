#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// 새로운 형태의 보고서를 추가해도 기존 클래스 수정 불필요
class Report
{
    public:
        virtual void generate() = 0;
        virtual ~Report() = default;
};
class PDFReport : public Report
{
    public:
        void generate() override
        {
            cout<<"PDF 보고서 생성"<<"\n";
        }
};

class HTMLReport : public Report
{
    public:
        void generate() override
        {
            cout<<"HTML 보고서 생성"<<"\n";
        }
};

class ReportGenerator
{
    public:
        void addReport(shared_ptr<Report> report)
        {
            reports.push_back(report);
        }

        void generateReports()
        {
            for(const auto& report : reports)
            {
                report->generate();
            }
        }

    private:
        vector<shared_ptr<Report>> reports;
};