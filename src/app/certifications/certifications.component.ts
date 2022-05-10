import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-certifications',
  templateUrl: './certifications.component.html',
  styleUrls: ['./certifications.component.css']
})
export class CertificationsComponent implements OnInit {
  certifications: Array<{title: string, exDate: string}>;;
  constructor() {
    this.certifications = [{title:"AWS Certified Cloud Practitioner", exDate: "January 2022 - 2025"},
                      {title:"Microsoft Certified: Azure Fundamentals", exDate: "February 2022 - "},
                      {title:"Coursera: Deep Learning Specialization", exDate: "June 2020 - "}];
   }

  ngOnInit(): void {
    
  }

}
