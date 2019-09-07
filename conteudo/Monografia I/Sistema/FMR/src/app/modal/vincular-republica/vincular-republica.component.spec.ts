import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { VincularRepublicaComponent } from './vincular-republica.component';

describe('VincularRepublicaComponent', () => {
  let component: VincularRepublicaComponent;
  let fixture: ComponentFixture<VincularRepublicaComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ VincularRepublicaComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(VincularRepublicaComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
