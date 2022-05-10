import { Component, OnInit, ElementRef, ViewChild } from '@angular/core';

@Component({
  selector: 'app-nav',
  templateUrl: './nav.component.html',
  styleUrls: ['./nav.component.css'],
})
export class NavComponent implements OnInit {
  title: String = '';
  newTitle: String = 'Stephen Valente';
  menuShowing: Boolean = false;
  constructor() {}

  ngOnInit() {
    
    this.loadName();
  }
  async loadName() {
    for (let i = 0; i < this.newTitle.length; i++) {
      
      this.title += this.newTitle[i];
      await this.delay(Math.random()*200);
    }
    
  }
  delay(ms: number) {
    return new Promise( resolve => setTimeout(resolve, ms) );
  }
  onClick() {
    this.menuShowing = !this.menuShowing;
  }
  hasClass(el: any) {
    return !(el.getAttribute('show') !== -1);
  }
  
}

