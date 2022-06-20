import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-projects',
  templateUrl: './projects.component.html',
  styleUrls: ['./projects.component.css']
})
export class ProjectsComponent implements OnInit {
  projects = [
    {about:"Online mitigation service written in C# using .NET Core, Entity Framework Core", images:[
      "https://raw.githubusercontent.com/steviev93/RelationshipMattersFamilyServicesWebsite/main/Mainpage(desktop).png",
      "https://raw.githubusercontent.com/steviev93/RelationshipMattersFamilyServicesWebsite/main/Contact(desktop).png",
      "https://raw.githubusercontent.com/steviev93/RelationshipMattersFamilyServicesWebsite/main/BioPage(desktop).png"
    ]},
    {about:"POS built with JavaFX, SceneBuilder, and MySQL", images: [
      "https://raw.githubusercontent.com/steviev93/POS/master/Screen%20Shot%202021-12-17%20at%205.17.27%20PM.png",
      "https://raw.githubusercontent.com/steviev93/POS/master/Screen%20Shot%202021-12-17%20at%205.14.27%20PM.png",
      "https://raw.githubusercontent.com/steviev93/POS/master/Screen%20Shot%202021-12-17%20at%205.17.44%20PM.png"
    ]},
    {about:"Final project for school. POC of a business called Valente's Pizza. This was built using C#, .NET Core, Angular, Entity Framework Core, and SQL Server. Code review of the initial project I reworked: https://www.youtube.com/watch?v=MQ5GnWyXU-U", images: [
      "https://raw.githubusercontent.com/steviev93/ValentesPizzaClient/main/OrderScreen.png",
      "https://raw.githubusercontent.com/steviev93/ValentesPizzaAdmin/master/AdminAddProduct.png",
      "https://raw.githubusercontent.com/steviev93/ValentesPizzaAdmin/master/AdminLogin.png"
    ]},
  ]
  constructor() { }

  ngOnInit(): void {
  }

}
