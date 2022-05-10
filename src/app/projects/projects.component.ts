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
    ]}
  ]
  constructor() { }

  ngOnInit(): void {
  }

}
