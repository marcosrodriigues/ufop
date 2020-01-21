import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { RecomendarComponent } from './recomendar.component';

describe('RecomendarComponent', () => {
  let component: RecomendarComponent;
  let fixture: ComponentFixture<RecomendarComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ RecomendarComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(RecomendarComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
